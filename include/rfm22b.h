/* Copyright (c) 2013 Owen McAree
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/* Class to control the HopeRF RFM22B module
 *	Inherits SPI functionality from SPI class
 *	This class is a work in progress, at present all it can do is get/set the carrier
 *	frequency. This has been tested on the 868MHz modules but should work for all
 *	frequencies (High or Low bands 24-47, See Table 12 of the datasheet).
 */
 
#ifndef rfm22b_h
#define rfm22b_h

#include "spi.h"

class RFM22B : public SPI {
public:
	// Include enums from separate file
	//	This is inside class definition so enums stay within class scope
	#include "rfm22b_enums.h"

	// Constructor requires SPI device path, passes this is SPI class
	RFM22B(const char *device) : SPI(device) {}
	
	// Set or get the carrier frequency (in Hz);
	void setCarrierFrequency(unsigned int frequency);
	unsigned int getCarrierFrequency();
	
	// Set or get the frequency hopping step size (in Hz, but it is floored to nearest 10kHz)
	void setFrequencyHoppingStepSize(unsigned int step);
	unsigned int getFrequencyHoppingStepSize();
	
	// Set or get the frequency hopping channel
	void setChannel(uint8_t channel);
	uint8_t getChannel();
	
	// Set or get the frequency deviation (in Hz, but floored to the nearest 625Hz)
	void setFrequencyDeviation(unsigned int deviation);
	unsigned int getFrequencyDeviation();
	
	// Set or get the data rate (bps)
	void setDataRate(unsigned int rate);
	unsigned int getDataRate();
	
	// Set or get the modulation type
	void setModulationType(RFM22B_Modulation_Type modulation);
	RFM22B_Modulation_Type getModulationType();
	
	// Set or get the modulation data source
	void setModulationDataSource(RFM22B_Modulation_Data_Source source);
	RFM22B_Modulation_Data_Source getModulationDataSource();
	
	// Set or get the data clock source
	void setDataClockConfiguration(RFM22B_Data_Clock_Configuration clock);
	RFM22B_Data_Clock_Configuration getDataClockConfiguration();
	
	// Set or get the transmission power
	void setTransmissionPower(uint8_t power);
	uint8_t getTransmissionPower();
	
	// Set or get the GPIO configuration
	void setGPIOFunction(RFM22B_GPIO gpio, RFM22B_GPIO_Function funct);
	// This should probably return enum, but this needs a lot of cases
	uint8_t getGPIOFunction(RFM22B_GPIO gpio);
	
	
	// Helper functions for getting and getting individual registers
	uint8_t getRegister(uint8_t reg);
	void setRegister(uint8_t reg, uint8_t value);	
	
private:

};
#include "rfm22b_enums.h"
#endif