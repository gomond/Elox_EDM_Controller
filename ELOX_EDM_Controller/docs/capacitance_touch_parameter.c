FT5x06 I2C address is 0x38

#ifdef CONFIG_LCD_HY070CTP    // same with HY050CTP-HD
struct ft5x0x_platform_data ft5306_info = {
  .model = 5206,
  .max_x = 800,
  .max_y = 480,
  .key_min_x = 1024,
  .xy_swap = 0,
  .x_revert = 0,
  .y_revert = 0,
  .init_platform_hw= ft5306_init_platform_hw,
  .exit_platform_hw= ft5306_exit_platform_hw,
  .ft5x0x_platform_sleep  = ft5306_platform_sleep,
  .ft5x0x_platform_wakeup = ft5306_platform_wakeup,
};
#endif

#ifdef CONFIG_LCD_HY070CTP_HD
struct ft5x0x_platform_data ft5306_info = {
  .model = 5206,
  .max_x = 1024,
  .max_y = 600,
  .key_min_x = 1024,
  .xy_swap = 0,
  .x_revert = 0,
  .y_revert = 1,  //Important
  .init_platform_hw= ft5306_init_platform_hw,
  .exit_platform_hw= ft5306_exit_platform_hw,
  .ft5x0x_platform_sleep  = ft5306_platform_sleep,
  .ft5x0x_platform_wakeup = ft5306_platform_wakeup,
};
#endif

#ifdef CONFIG_LCD_HY101CTP  // same with HY070CTP-HD-RGB
struct ft5x0x_platform_data ft5306_info = {
  .model = 5406,
  .max_x = 1024,
  .max_y = 600,
  .key_min_x = 1024,
  .xy_swap = 0,
  .x_revert = 0,
  .y_revert = 0,  //different with HY070CTP_HD, the drive is same. if you want to use fully compatible with HY070CTP_HD, can be customized.
  .init_platform_hw= ft5306_init_platform_hw,
  .exit_platform_hw= ft5306_exit_platform_hw,
  .ft5x0x_platform_sleep  = ft5306_platform_sleep,
  .ft5x0x_platform_wakeup = ft5306_platform_wakeup,
};
#endif