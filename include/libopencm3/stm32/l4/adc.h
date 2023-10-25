/** @defgroup adc_defines ADC Defines
 *
 * @brief <b>Defined Constants and Types for the STM32L4xx Analog to Digital
 * Converter</b>
 *
 * @ingroup STM32L4xx_defines
 *
 * @version 1.0.0
 *
 * @date 24 Oct 2015
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Karl Palsson <karlp@tweak.net.au>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENCM3_ADC_H
#define LIBOPENCM3_ADC_H

#include <libopencm3/stm32/common/adc_common_v2.h>
#include <libopencm3/stm32/common/adc_common_v2_multi.h>

/**@{*/

/** @defgroup adc_reg_base ADC register base addresses
 * @ingroup adc_defines
 *
 *@{*/
#define ADC1				ADC1_BASE
#define ADC2				ADC2_BASE
#define ADC3				ADC3_BASE
/**@}*/

/** @defgroup adc_channel ADC Channel Numbers
 * @ingroup adc_defines
 *
 *@{*/
#define ADC_CHANNEL_VREF	0
#define ADC_CHANNEL_TEMP	17
#define ADC_CHANNEL_VBAT	18
/**@}*/

/* ADC_CR Values ------------------------------------------------------------*/

/* DEEPPWD: Deep power down */
#define ADC_CR_DEEPPWD		(1 << 29)

/* ADVREGEN: Voltage regulator enable bit */
#define ADC_CR_ADVREGEN		(1 << 28)

/* ADC_CFGR1 Values ---------------------------------------------------------*/

/** ALIGN: Data alignment */
#define ADC_CFGR1_ALIGN			(1 << 5)

/* EXTSEL[2:0]: External trigger selection for regular group */
#define ADC_CFGR1_EXTSEL_SHIFT		6
#define ADC_CFGR1_EXTSEL_MASK		(0xf << ADC_CFGR1_EXTSEL_SHIFT)
#define ADC_CFGR1_EXTSEL_VAL(x)		((x) << ADC_CFGR1_EXTSEL_SHIFT)

/*------- ADC_CFGR2 values ---------*/

/** ROVSE: Regular Oversampling Enable */
#define ADC_CFGR2_ROVSE				(1 << 0)

/** JOVSE: Injected Oversampling Enable */
#define ADC_CFGR2_JOVSE				(1 << 1)

/** OVSR[2:0]: Oversampling ratio */
#define ADC_CFGR2_OVSR_SHIFT			2
#define ADC_CFGR2_OVSR_MASK			(0x7 << ADC_CFGR2_OVSR_SHIFT)
#define ADC_CFGR2_OVSR_VAL(x)			((x) << ADC_CFGR2_OVSR_SHIFT)

#define ADC_CFGR2_OVSR_2x			ADC_CFGR2_OVSR_VAL(0)
#define ADC_CFGR2_OVSR_4x			ADC_CFGR2_OVSR_VAL(1)
#define ADC_CFGR2_OVSR_8x			ADC_CFGR2_OVSR_VAL(2)
#define ADC_CFGR2_OVSR_16x			ADC_CFGR2_OVSR_VAL(3)
#define ADC_CFGR2_OVSR_32x			ADC_CFGR2_OVSR_VAL(4)
#define ADC_CFGR2_OVSR_64x			ADC_CFGR2_OVSR_VAL(5)
#define ADC_CFGR2_OVSR_128x			ADC_CFGR2_OVSR_VAL(6)
#define ADC_CFGR2_OVSR_256x			ADC_CFGR2_OVSR_VAL(7)

/** OVSS[3:0]: Oversampling shift */
#define ADC_CFGR2_OVSS_SHIFT			5
#define ADC_CFGR2_OVSS_MASK			(0xf << ADC_CFGR2_OVSS_SHIFT)
#define ADC_CFGR2_OVSS_VAL(x)			((x) << ADC_CFGR2_OVSS_SHIFT)

/** TROVS: Triggered Regular Oversampling */
#define ADC_CFGR2_TROVS				(1 << 9)

/** ROVSM: Regular Oversampling mode */
#define ADC_CFGR2_ROVSM				(1 << 10)

/** GCOMP: Gain compensation mode */
#define ADC_CFGR2_GCOMP				(1 << 16)

/** SWTRIG: Software trigger bit for sampling time control trigger mode */
#define ADC_CFGR2_SWTRIG			(1 << 25)

/** BULB: Bulb sampling mode */
#define ADC_CFGR2_BULB				(1 << 26)

/** SMPTRIG: Sampling time control trigger mode */
#define ADC_CFGR2_SMPTRIG			(1 << 27)

/****************************************************************************/
/* ADC_SMPRx ADC Sample Time Selection for Channels */
/** @defgroup adc_sample ADC Sample Time Selection values
@ingroup adc_defines

@{*/
#define ADC_SMPR_SMP_2DOT5CYC		0x0
#define ADC_SMPR_SMP_6DOT5CYC		0x1
#define ADC_SMPR_SMP_12DOT5CYC		0x2
#define ADC_SMPR_SMP_24DOT5CYC		0x3
#define ADC_SMPR_SMP_47DOT5CYC		0x4
#define ADC_SMPR_SMP_92DOT5CYC		0x5
#define ADC_SMPR_SMP_247DOT5CYC		0x6
#define ADC_SMPR_SMP_640DOT5CYC		0x7
/**@}*/


BEGIN_DECLS

void adc_enable_deeppwd(uint32_t adc);
void adc_disable_deeppwd(uint32_t adc);
void adc_enable_reg_ovrsmp(uint32_t adc);
void adc_disable_reg_ovrsmp(uint32_t adc);
void adc_set_ovrsmp_ratio(uint32_t adc, uint16_t ratio);
void adc_set_ovrsmp_shift(uint32_t adc, uint16_t shift);


END_DECLS


#endif
