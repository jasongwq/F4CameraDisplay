#ifndef __MT9D111_H__
#define __MT9D111_H__

/* Includes ------------------------------------------------------------------*/
#include <stm32f4xx_i2c.h>
/* Private typedef -----------------------------------------------------------*/
typedef unsigned char uchar;
typedef unsigned short ushort;

/* Private define ------------------------------------------------------------*/
#define MT9D111_I2C   I2C1      // Interfejs szeregowy kamery podlaczony do szyny I2C1
#define RESOLUTION    SVGA      // Rozdzielczosc wyjsciowa z kamery 800x600
#define XCLK          PLL_56MHz // Czestotliwosc sygnalu taktujacego uklad kamery XCLK
#define PIXCLK        F_25MHz   // Czestotliwosc sygnalu PIXCLK

#define MT9D111_DEVICE_WRITE_ADDRESS  0xBA
#define MT9D111_DEVICE_READ_ADDRESS   0xBB
#define MT9D111_DELAY                 0xF0
#define MT9D111_TERM                  0xFF
#define EIO                           1
#define I2C_TIMEOUT_MAX               10000

/**************************************
# Display resolution standards #
        QCIF    : 176 x 144
        CIF     : 352 x 288
        QVGA    : 320 x 240
        VGA     : 640 x 480 (4:3)
        SVGA    : 800 x 600 (4:3)
        XGA     : 1024 x 768 (4:3)
				XGA+    : 1152 x 864 (4:3)
        WXGA    : 1280 x 800 (16:10)
        QVGA    : 1280 x 960 
        SXGA    : 1280 x 1024 
        SXGA+   : 1400 x 1050 
        WSXGA+  : 1680 x 1050 
        UXGA    : 1600 x 1200 
        WUXGA   : 1920 x 1200 
        QXGA    : 2048 x 1536
**************************************/
#define QVGA                    0x01
#define SVGA                    0x02
#define UXGA                    0x03

#define HSE_8MHz                0x01
#define PLL_33MHz               0x02
#define PLL_56MHz               0x03
#define F_10MHz                 10
#define F_20MHz                 20
#define F_25MHz                 25
#define F_40MHz                 40
#define F_50MHz                 50

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
struct MT9D111_REG_STRUCT{
	unsigned char page;
	unsigned char subaddr;
	unsigned short value;
};

/* Extern functions ----------------------------------------------------------*/
extern void Delay(__IO uint32_t nTime);
/* Private function prototypes -----------------------------------------------*/
int MT9D111_SetRegs(struct MT9D111_REG_STRUCT *init);
void MT9D111_Init(void);
void MT9D111_SoftReset(void);
ushort MT9D111_ReadReg(uchar regAddr);
uchar MT9D111_WriteReg(uchar regAddr, ushort regVal);
ushort MT9D111_ReadVar(uchar driverID, uchar varOffset, uchar varSize);
uchar MT9D111_WriteVar(uchar driverID, uchar varOffset, uchar varSize, ushort varData);

/* Register names ------------------------------------------------------------*/
/* Page 0 --- Sensor registers */
#define ROW_START_REG						0x01
#define COL_START_REG						0x02
#define ROW_WIDTH_REG						0x03
#define COL_WIDTH_REG						0x04
#define H_BLANKING_CTX_B_REG		0x05
#define V_BLANKING_CTX_B_REG		0x06
#define H_BLANKING_CTX_A_REG		0x07
#define V_BLANKING_CTX_A_REG		0x08
#define SHUTTER_WIDTH_REG				0x09
#define ROW_SPEED_REG						0x0A
#define EXTRA_DELAY_REG					0x0B
#define SHUTTER_DELAY_REG				0x0C
#define RESET_REG								0x0D
#define FRAME_VALID_CTRL_REG		0x1F
#define READ_MODE_CTX_B_REG			0x20
#define READ_MODE_CTX_A_REG			0x21
#define SHOW_CTRL_REG						0x22
#define FLASH_CTRL_REG					0x23
#define EXTRA_RESET_REG					0x24
#define LINE_VALID_CTRL_REG			0x25
#define BOTTOM_DARK_ROWS_REG		0x26
#define GREEN1_GAIN_REG					0x2B
#define BLUE_GAIN_REG						0x2C
#define RED_GAIN_REG						0x2D
#define GREEN2_GAIN_REG					0x2E
#define GLOBAL_GAIN_REG					0x2F
#define ROW_NOISE_REG						0x30
#define BLACK_ROWS_REG					0x59
#define GREEN1_FRAME_AVRG_REG		0x5B
#define BLUE_FRAME_AVRG_REG			0x5C
#define RED_FRAME_AVRG_REG			0x5D
#define GREEN2_FRAME_AVRG_REG		0x5E
#define THRESHOLD_REG						0x5F
#define CALIBRATION_CTRL_REG		0x60
#define GREEN1_CALIBR_VALUE_REG	0x61
#define BLUE_CALIBR_VALUE_REG		0x62
#define RED_CALIBR_VALUE_REG		0x63
#define GREEN2_CALIBR_VALUE_REG	0x64
#define CLOCK_REG								0x65
#define PLL_CTRL1_REG						0x66
#define PLL_CTRL2_REG						0x67
#define GLOBAL_RESET_CTRL_REG		0xC0
#define START_INT_TIME_REG			0xC1
#define START_READOUT_TIME_REG	0xC2
#define ASSERT_STRB_TIME_REG		0xC3
#define DEASSERT_STRB_TIME_REG	0xC4
#define ASSERT_FLASH_TIME_REG		0xC5
#define DEASSERT_FLASH_TIME_REG	0xC6
#define AIN3_SAMPLE_REG					0xE0
#define AIN2_SAMPLE_REG					0xE1
#define AIN1_SAMPLE_REG					0xE2
#define EXT_SIGN_SAMP_CTRL_REG	0xE3
#define PAGE_SELECT_REG					0xF0
#define BYTEWISE_ADRR_REG				0xF1
#define CTX_CTRL_REG						0xF2

/* Page 1 - IFP Registers */
#define COLOR_PIPELINE_CTRL_REG 0x08
#define FACTORY_BYPASS_REG      0x09
#define PAD_SLEW_REG            0x0A
#define INTERNAL_CLOCK_CTRL_REG 0x0B
#define X0_COORD_CROP_WIN_REG   0x11
#define X1_COORD_CROP_WIN_REG   0x12
#define Y0_COORD_CROP_WIN_REG   0x13
#define Y1_COORD_CROP_WIN_REG   0x14
#define DECIMATOR_CTRL_REG      0x21
#define WEIGHT_H_DECIMATION_REG 0x16
#define WEIGHT_V_DECIMATION_REG 0x17
//...
#define TEST_PATTERN_REG        0x48
#define TEST_PATTERN_R_REG      0x49
#define TEST_PATTERN_G_REG      0x4A
#define TEST_PATTERN_B_REG      0x4B
//...
#define OUTPUT_FORMAT_CONF_REG  0x97
#define OUTPUT_FORMAT_TEST_REG  0x98
#define LINE_COUNT_REG          0x99
#define FRAME_COUNT_REG         0x9A
#define SPEC_EFFECTS_REG        0xA4
//...
#define UC_BOOT_MODE_REG        0xC3
#define UC_VAR_ADDR_REG         0xC6
#define UC_VAR_DATA_REG         0xC8
//...

/* Page 2 - IFP Registers */
//...

#endif /*__MT9D111_H__*/
