/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <stdarg.h>
#include <touchgfx/TextProvider.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/TypedText.hpp>
#include <touchgfx/Unicode.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <texts/TypedTextDatabase.hpp>

uint16_t touchgfx::Font::getStringWidth(const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(TEXT_DIRECTION_LTR, text, pArg);
    va_end(pArg);
    return width;
}

uint16_t touchgfx::Font::getStringWidth(touchgfx::TextDirection textDirection, const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(textDirection, text, pArg);
    va_end(pArg);
    return width;
}

touchgfx::Unicode::UnicodeChar touchgfx::TextProvider::getNextLigature(TextDirection direction)
{
    if (fontGsubTable && nextCharacters.peekChar())
    {
        substituteGlyphs();
        if (nextCharacters.peekChar(1) == 0x093F) // Hindi I-matra
        {
            nextCharacters.replaceAt1(nextCharacters.peekChar());
            nextCharacters.replaceAt0(0x093F);
        }
    }
    return getNextChar();
}

void touchgfx::TextProvider::initializeInternal()
{
    fillInputBuffer();
}

void touchgfx::LCD::drawString(touchgfx::Rect widgetArea, const touchgfx::Rect& invalidatedArea, const touchgfx::LCD::StringVisuals& stringVisuals, const touchgfx::Unicode::UnicodeChar* format, ...)
{
    va_list pArg;
    va_start(pArg, format);
    drawStringLTR(widgetArea, invalidatedArea, stringVisuals, format, pArg);
    va_end(pArg);
}

// Default TypedTextDatabase
extern const touchgfx::TypedText::TypedTextData* const typedTextDatabaseArray[];

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const touchgfx::Unicode::UnicodeChar texts_all_languages[] TEXT_LOCATION_FLASH_ATTRIBUTE = {
    0x43, 0x75, 0x72, 0x72, 0x65, 0x6e, 0x74, 0x20, 0x4c, 0x69, 0x76, 0x65, 0x20, 0x50, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x0, // @0 "Current Live Position"
    0x45, 0x4c, 0x4f, 0x58, 0x20, 0x45, 0x44, 0x4d, 0x20, 0x43, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x6c, 0x65, 0x72, 0x0, // @22 "ELOX EDM Controller"
    0x52, 0x65, 0x74, 0x72, 0x61, 0x63, 0x74, 0x20, 0x44, 0x69, 0x73, 0x74, 0x61, 0x6e, 0x63, 0x65, 0x0, // @42 "Retract Distance"
    0x55, 0x70, 0x70, 0x65, 0x72, 0x20, 0x52, 0x61, 0x6d, 0x20, 0x4c, 0x69, 0x6d, 0x69, 0x74, 0x0, // @59 "Upper Ram Limit"
    0x2, 0x0, // @75 "<>"
    0x43, 0x75, 0x74, 0x20, 0x49, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x0, // @77 "Cut Interval"
    0x46, 0x69, 0x6e, 0x69, 0x73, 0x68, 0x20, 0x44, 0x65, 0x70, 0x74, 0x68, 0x0, // @90 "Finish Depth"
    0x30, 0x30, 0x30, 0x2e, 0x30, 0x30, 0x30, 0x30, 0x0, // @103 "000.0000"
    0x4b, 0x42, 0xa, 0x45, 0x78, 0x69, 0x74, 0x0, // @112 "KB\nExit"
    0x4e, 0x75, 0x6d, 0x54, 0x78, 0x74, 0x0, // @120 "NumTxt"
    0x52, 0x65, 0x6c, 0x61, 0x79, 0x31, 0x0, // @127 "Relay1"
    0x52, 0x65, 0x6c, 0x61, 0x79, 0x32, 0x0, // @134 "Relay2"
    0x52, 0x65, 0x6c, 0x61, 0x79, 0x33, 0x0, // @141 "Relay3"
    0x52, 0x65, 0x6c, 0x61, 0x79, 0x34, 0x0, // @148 "Relay4"
    0x52, 0x65, 0x6c, 0x61, 0x79, 0x73, 0x0, // @155 "Relays"
    0x5a, 0x65, 0x72, 0x6f, 0x20, 0x5a, 0x0, // @162 "Zero Z"
    0x41, 0x75, 0x74, 0x6f, 0x0, // @169 "Auto"
    0x42, 0x61, 0x63, 0x6b, 0x0, // @174 "Back"
    0x49, 0x6e, 0x63, 0x68, 0x0, // @179 "Inch"
    0x31, 0x32, 0x33, 0x0, // @184 "123"
    0x41, 0x42, 0x43, 0x0, // @188 "ABC"
    0x4d, 0x61, 0x6e, 0x0, // @192 "Man"
    0x4d, 0x4d, 0x0, // @196 "MM"
    0x4f, 0x4b, 0x0 // @199 "OK"
};

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const uint32_t indicesGb[] TEXT_LOCATION_FLASH_ATTRIBUTE;

// Array holding dynamically installed languages
struct TranslationHeader
{
    uint32_t offset_to_texts;
    uint32_t offset_to_indices;
    uint32_t offset_to_typedtext;
};
static const TranslationHeader* languagesArray[1] = { 0 };

// Compiled and linked in languages
static const uint32_t* const staticLanguageIndices[] = {
    indicesGb
};

touchgfx::LanguageId touchgfx::Texts::currentLanguage = static_cast<touchgfx::LanguageId>(0);
static const touchgfx::Unicode::UnicodeChar* currentLanguagePtr = 0;
static const uint32_t* currentLanguageIndices = 0;

void touchgfx::Texts::setLanguage(touchgfx::LanguageId id)
{
    const touchgfx::TypedText::TypedTextData* currentLanguageTypedText = 0;
    if (id < 1)
    {
        if (languagesArray[id] != 0)
        {
            // Dynamic translation is added
            const TranslationHeader* translation = languagesArray[id];
            currentLanguagePtr = (const touchgfx::Unicode::UnicodeChar*)(((const uint8_t*)translation) + translation->offset_to_texts);
            currentLanguageIndices = (const uint32_t*)(((const uint8_t*)translation) + translation->offset_to_indices);
            currentLanguageTypedText = (const touchgfx::TypedText::TypedTextData*)(((const uint8_t*)translation) + translation->offset_to_typedtext);
        }
        else
        {
            // Compiled and linked in languages
            currentLanguagePtr = texts_all_languages;
            currentLanguageIndices = staticLanguageIndices[id];
            currentLanguageTypedText = typedTextDatabaseArray[id];
        }
    }

    if (currentLanguageTypedText)
    {
        currentLanguage = id;
        touchgfx::TypedText::registerTypedTextDatabase(currentLanguageTypedText,
                                                       TypedTextDatabase::getFonts(), TypedTextDatabase::getInstanceSize());
    }
}

void touchgfx::Texts::setTranslation(touchgfx::LanguageId id, const void* translation)
{
    languagesArray[id] = (const TranslationHeader*)translation;
}

const touchgfx::Unicode::UnicodeChar* touchgfx::Texts::getText(TypedTextId id) const
{
    return &currentLanguagePtr[currentLanguageIndices[id]];
}
