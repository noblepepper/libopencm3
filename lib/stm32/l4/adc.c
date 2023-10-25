/** @defgroup adc_file ADC

@ingroup STM32L4xx

@brief <b>libopencm3 STM32L4xx Analog to Digital Converters</b>

@author @htmlonly &copy; @endhtmlonly 2016 Karl Palsson <karlp@tweak.net.au>


LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Karl Palsson <karlp@tweak.net.au>
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

#include <libopencm3/stm32/adc.h>

/**@{*/

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Deep-Power-Down Mdoe
 *
 * Deep-power-down mode allows additional power saving by internally switching
 * off to reduce leakage currents.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */
void adc_enable_deeppwd(uint32_t adc)
{
	ADC_CR(adc) |= ADC_CR_DEEPPWD;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Deep-Power-Down Mdoe
 *
 * Deep-power-down mode allows additional power saving by internally switching
 * off to reduce leakage currents.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */
void adc_disable_deeppwd(uint32_t adc)
{
	ADC_CR(adc) &= ~ADC_CR_DEEPPWD;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Regular Oversampling
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */
void adc_enable_reg_ovrsmp(uint32_t adc)
{
	ADC_CFGR2(adc) |= ADC_CFGR2_ROVSE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Regular Oversampling
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */
void adc_disable_reg_ovrsmp(uint32_t adc)
{
	ADC_CFGR2(adc) &= ~ADC_CFGR2_ROVSE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set Oversampling Ratio
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */
void adc_set_ovrsmp_ratio(uint32_t adc, uint16_t ratio)
{
	ADC_CFGR2(adc) |= (ratio);
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set Oversampling Shift
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */
void adc_set_ovrsmp_shift(uint32_t adc, uint16_t shift)
{
	ADC_CFGR2(adc) |= (shift << ADC_CFGR2_OVSS_SHIFT);
}



/**
 * Enable the ADC Voltage regulator
 * Before any use of the ADC, the ADC Voltage regulator must be enabled.
 * You must wait up to 10uSecs afterwards before trying anything else.
 * @param[in] adc ADC block register address base
 * @sa adc_disable_regulator
 */
void adc_enable_regulator(uint32_t adc)
{
	ADC_CR(adc) |= ADC_CR_ADVREGEN;
}

/**
 * Disable the ADC Voltage regulator
 * You can disable the adc vreg when not in use to save power
 * @param[in] adc ADC block register address base
 * @sa adc_enable_regulator
 */
void adc_disable_regulator(uint32_t adc)
{
	ADC_CR(adc) &= ~ADC_CR_ADVREGEN;
}

/**@}*/
