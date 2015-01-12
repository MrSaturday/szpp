#ifndef _SZPP_HAL_GPIO_H_
#define _SZPP_HAL_GPIO_H_

#include <cfg/csp/stm32f4xx.h>
#include <utils/typedefs.h>

namespace hal
{

class gpio
{
public:
    enum class mode : u8
    {
        out = 0x01
    };

    gpio(u32 port)
    {
        enablePeripheralClock(port);
        regBank = calulateStartAddress(port);
    }

    void configure(mode m, u32 pin)
    {
        (void)m;
        regBank->MODER |= static_cast<u8>(m) << (2*pin);
    }

    void setPin(u32 pin)
    {
        regBank->BSRRL |= 1 << pin;
    }

private:
    void enablePeripheralClock(u32 port)
    {
        RCC->AHB1ENR |= 1 << port;
    }

    GPIO_TypeDef* calulateStartAddress(u32 port)
    {
        return reinterpret_cast<GPIO_TypeDef*>(GPIOA_BASE + port*memoryRange);
    }

    GPIO_TypeDef* regBank;
    static const u32 memoryRange = GPIOB_BASE - GPIOA_BASE;
};

}

#endif /* _SZPP_HAL_GPIO_H_ */
