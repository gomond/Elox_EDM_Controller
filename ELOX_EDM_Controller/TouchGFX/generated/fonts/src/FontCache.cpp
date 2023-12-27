/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <cstring>
#include <touchgfx/TextProvider.hpp>
#include <touchgfx/Utils.hpp>
#include <fonts/CachedFont.hpp>
#include <fonts/FontCache.hpp>
#include <texts/TypedTextDatabase.hpp>

namespace touchgfx
{
FontCache::FontCache()
    : memorySize(0), memory(0), top(0), gsubStart(0), reader(0)
{
}

void FontCache::clear(bool keepGsubOrContextTable /* = false */)
{
    memset(fontTable, 0, sizeof(fontTable));

    // Top is beginning of memory, no glyphs are cached yet
    top = memory;

    if (!keepGsubOrContextTable)
    {
        // gsubStart points to end of memory (nothing loaded yet)
        gsubStart = memory + memorySize;

        // Round down to 32bit address
        gsubStart = (uint8_t*)((uintptr_t)gsubStart & ~(sizeof(void*) - 1));
    }
}

void FontCache::setMemory(uint8_t* _memory, uint32_t size)
{
    memory = _memory;
    memorySize = size;

    clear();
}

void FontCache::setReader(FontDataReader* _reader)
{
    reader = _reader;
}

const GlyphNode* FontCache::getGlyph(Unicode::UnicodeChar unicode, FontId font) const
{
    GlyphNode* g = (GlyphNode*)fontTable[font].first;
    while (g)
    {
        if (g->unicode == unicode)
        {
            return g;
        }
        GlyphNode** next = (GlyphNode**)((uint8_t*)g + SizeGlyphNode);
        g = *next;
    }
    return 0;
}

void FontCache::open()
{
    if (reader)
    {
        reader->open();
    }
}

void FontCache::close()
{
    if (reader)
    {
        reader->close();
    }
}

void FontCache::initializeCachedFont(TypedText t, CachedFont* font, bool loadGsubOrContextTable /*= false*/)
{
    // Get font index from typed text
    FontId fontId = t.getFontId();
    // Reset to start of file
    open();
    setPosition(0);

    assert(sizeof(touchgfx::BinaryFontData) < MAX_BUFFER_SIZE);
    readData(buffer, sizeof(touchgfx::BinaryFontData));
    const struct touchgfx::BinaryFontData* binaryFontData = reinterpret_cast<const struct touchgfx::BinaryFontData*>(buffer);

    const Font** flashFonts = TypedTextDatabase::getFonts();
    const GeneratedFont* flashFont = static_cast<const GeneratedFont*>(flashFonts[fontId]);
    *font = CachedFont(reinterpret_cast<const struct touchgfx::BinaryFontData*>(buffer), fontId, this, flashFont);

    if (loadGsubOrContextTable && (binaryFontData->offsetToGSUB != 0))
    {
        setPosition(binaryFontData->offsetToGSUB);

        const uint32_t sizeOfGSUB = (binaryFontData->offsetToArabicTable != 0 ? binaryFontData->offsetToArabicTable : binaryFontData->sizeOfFontData) - binaryFontData->offsetToGSUB;

        if (top + sizeOfGSUB < gsubStart) // Room for this GSUB table
        {
            // Round down to aligned address
            uint8_t* const gsubPosition = (uint8_t*)((uintptr_t)(gsubStart - sizeOfGSUB) & ~(sizeof(void*) - 1));
            readData(gsubPosition, sizeOfGSUB);
            font->setGSUBTable(reinterpret_cast<uint16_t*>(gsubPosition));
            gsubStart = gsubPosition;
        }
        else
        {
            font->setGSUBTable(0);
        }
    }

    if (loadGsubOrContextTable && (binaryFontData->offsetToArabicTable != 0))
    {
        setPosition(binaryFontData->offsetToArabicTable);

        const uint32_t sizeTableData = binaryFontData->sizeOfFontData - binaryFontData->offsetToArabicTable;

        if (top + sizeTableData + sizeof(FontContextualFormsTable) < gsubStart) // Room for the ContextualFormsTables
        {
            // Allocate FontContextualFormsTable first
            gsubStart -= sizeof(FontContextualFormsTable);
            // Round down to 32bit address
            gsubStart = (uint8_t*)((uintptr_t)gsubStart & ~(sizeof(void*) - 1));

            FontContextualFormsTable* table = (FontContextualFormsTable*)gsubStart;
            font->setContextualFormsTable(table);
            gsubStart -= sizeTableData;
            readData(gsubStart, sizeTableData);

            // Set pointers in table
            const uint16_t* const base = (const uint16_t*)gsubStart;
            // First elements in binary font are offsets to arrays in 16bit words
            table->contextualForms4Long = (FontContextualFormsTable::arrayOf5UnicodesPtr)(base + base[0]);
            table->contextualForms3Long = (FontContextualFormsTable::arrayOf5UnicodesPtr)(base + base[1]);
            table->contextualForms2Long = (FontContextualFormsTable::arrayOf5UnicodesPtr)(base + base[2]);
            table->contextualForms0621_063a = (FontContextualFormsTable::arrayOf4UnicodesPtr)(base + base[3]);
            table->contextualForms0641_064a = (FontContextualFormsTable::arrayOf4UnicodesPtr)(base + base[4]);
            table->contextualForms06XX = (FontContextualFormsTable::arrayOf5UnicodesPtr)(base + base[5]);
            table->contextualForms4LongSize = base[6];
            table->contextualForms3LongSize = base[7];
            table->contextualForms2LongSize = base[8];
            table->contextualForms06XXSize = base[9];
        }
        else
        {
            font->setContextualFormsTable(0);
        }
    }

    close();
}

bool FontCache::cacheString(TypedText t, const Unicode::UnicodeChar* string)
{
    open();
    if (!createSortedString(string))
    {
        close();
        return false;
    }
    const bool result = cacheSortedString(t);
    close();
    return result;
}

bool FontCache::cacheLigatures(CachedFont* font, TypedText t, const Unicode::UnicodeChar* string)
{
    open();
    if (!createSortedLigatures(font, t, string, 0, 0))
    {
        close();
        return false;
    }
    const bool result = cacheSortedString(t);
    close();
    return result;
}

bool FontCache::cacheSortedString(TypedText t)
{
    setPosition(8); // Skip font index and size
    uint32_t glyphNodeOffset;
    uint32_t dummy;
    readData(&glyphNodeOffset, sizeof(uint32_t)); // offsetToTable
    readData(&dummy, sizeof(uint32_t));           // offsetToKerning
    readData(&glyphDataOffset, sizeof(uint32_t)); // offsetToGlyphs
    readData(&dummy, sizeof(uint32_t));           // offsetToGlyphs
    readData(&dummy, sizeof(uint32_t));           // offsetToArabicTable
    readData(&numGlyphs, sizeof(uint16_t));       // numberOfGlyphs

    FontId fontId = t.getFontId();                 // Get font index from typed text
    bpp = t.getFont()->getBitsPerPixel();          // Get BPP from standard font
    byteAlignRow = t.getFont()->getByteAlignRow(); // Get ByteAlign from font

    setPosition(glyphNodeOffset); // Go to glyph nodes for font
    currentFileGlyphNumber = 0;
    currentFileGlyphNode.unicode = 0; // Force reading of first glyph

    const Unicode::UnicodeChar* string = sortedString;
    Unicode::UnicodeChar last = 0;
    GlyphNode* firstNewGlyph = 0;
    bool outOfMemory = false;
    while (*string)
    {
        Unicode::UnicodeChar ch = *string;
        if (ch != last)
        {
            if (!contains(ch, fontId))
            {
                insert(ch, fontId, outOfMemory);
                if (outOfMemory)
                {
                    break;
                }
                if (firstNewGlyph == 0)
                {
                    firstNewGlyph = (GlyphNode*)fontTable[fontId].last;
                }
            }
        }
        last = ch;
        string++;
    }

    cacheData(firstNewGlyph);
    return !outOfMemory;
}

bool FontCache::contains(Unicode::UnicodeChar unicode, FontId font) const
{
    GlyphNode* g = (GlyphNode*)fontTable[font].first;
    while (g)
    {
        if (g->unicode == unicode)
        {
            return true;
        }
        GlyphNode** next = (GlyphNode**)((uint8_t*)g + SizeGlyphNode);
        g = *next;
    }
    return false;
}

void FontCache::insert(Unicode::UnicodeChar unicode, FontId font, bool& outOfMemory)
{
    // Insert new glyphnode and glyph after last for font.
    uint8_t* oldTop = top;
    top = copyGlyph(top, unicode, font, outOfMemory);

    if (top == oldTop)
    {
        return;
    }

    if (fontTable[font].last == 0)
    {
        // First glyph
        fontTable[font].first = oldTop;
        fontTable[font].last = oldTop;
    }
    else
    {
        // Set next pointer of old last glyph
        uint8_t** old_next = (uint8_t**)(fontTable[font].last + SizeGlyphNode);
        *old_next = oldTop;

        // Save new glyph as last glyph
        fontTable[font].last = oldTop;
    }
}

uint8_t* FontCache::copyGlyph(uint8_t* top, Unicode::UnicodeChar unicode, FontId font, bool& outOfMemory)
{
    while (currentFileGlyphNumber < numGlyphs && currentFileGlyphNode.unicode < unicode)
    {
        readData(&currentFileGlyphNode, sizeof(GlyphNode));
        currentFileGlyphNumber++;
    }
    if (currentFileGlyphNode.unicode != unicode)
    {
        // GlyphNode not found
        return top;
    }

    // GlyphNode found
    uint32_t glyphSize = getGlyphSize(&currentFileGlyphNode);
    const int alignment = sizeof(void*);
    glyphSize = (glyphSize + (alignment - 1)) & ~(alignment - 1);
    uint32_t requiredMem = SizeGlyphNode + sizeof(void*) + glyphSize; // GlyphNode + next ptr + glyph

    // Is space available before sortedString
    if (top + requiredMem > (uint8_t*)sortedString)
    {
        outOfMemory = true;
        return top;
    }

    *(GlyphNode*)top = currentFileGlyphNode;

    // Clear next pointer
    uint8_t** next = (uint8_t**)(top + SizeGlyphNode);
    *next = 0;
    top += requiredMem;
    return top;
}

void FontCache::cacheData(GlyphNode* first)
{
    GlyphNode* gn = first;
    while (gn)
    {
        uint8_t* p = (uint8_t*)gn;
        if (gn->dataOffset != 0xFFFFFFFF)
        {
            p += SizeGlyphNode;
            // Next pointer
            p += sizeof(void*);

            // Seek and copy
            setPosition(glyphDataOffset + gn->dataOffset);
            readData(p, getGlyphSize(gn));

            // Mark glyphNode as cached
            gn->dataOffset = 0xFFFFFFFF;
        }

        GlyphNode** next = (GlyphNode**)((uint8_t*)gn + SizeGlyphNode);
        gn = *next;
    }
}

bool FontCache::createSortedString(const Unicode::UnicodeChar* string)
{
    int length = Unicode::strlen(string);
    // Sorted string is allocated at end of buffer
    sortedString = (Unicode::UnicodeChar*)(gsubStart - (length + 1) * 2);
    if ((uint8_t*)sortedString < top)
    {
        // Unable to allocate string buffer in end of memory
        return false;
    }
    int n = 0;
    Unicode::UnicodeChar* uc = sortedString;
    while (*string)
    {
        *uc++ = *string++;
        n++;
    }
    *uc = 0;
    return sortSortedString(n);
}

bool FontCache::createSortedLigatures(CachedFont* font, TypedText t, const Unicode::UnicodeChar* string, ...)
{
    va_list pArg;
    va_start(pArg, string);
    TextProvider tp;
    tp.initialize(string, pArg, font->getGSUBTable(), font->getContextualFormsTable());
    va_end(pArg);
    Unicode::UnicodeChar ligature;
    sortedString = (Unicode::UnicodeChar*)(gsubStart);
    if ((uint8_t*)(sortedString - 1) < top)
    {
        return false;
    }
    *--sortedString = 0;
    int n = 0;
    while ((ligature = tp.getNextLigature(t.getTextDirection())) != 0)
    {
        if ((uint8_t*)(sortedString - 1) < top)
        {
            return false;
        }
        *--sortedString = ligature;
        n++;
    }
    return sortSortedString(n);
}

bool FontCache::sortSortedString(int n)
{
    Unicode::UnicodeChar* uc = sortedString;
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (uc[j] > uc[j + 1])
            {
                Unicode::UnicodeChar temp = uc[j];
                uc[j] = uc[j + 1];
                uc[j + 1] = temp;
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop, then break
        if (!swapped)
        {
            break;
        }
    }
    return true;
}

void FontCache::setPosition(uint32_t position)
{
    if (reader)
    {
        reader->setPosition(position);
    }
}

void FontCache::readData(void* out, uint32_t numberOfBytes)
{
    if (reader)
    {
        reader->readData(out, numberOfBytes);
    }
}
} // namespace touchgfx
