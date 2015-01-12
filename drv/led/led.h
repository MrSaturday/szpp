#ifndef _CPPSZ_DRV_LED_H_
#define _CPPSZ_DRV_LED_H_

#include <cstddef>
#include <hal/gpio/gpio.h>
#include <utils/typedefs.h>

namespace drv
{

class led
{
public:
    led(u32 port, u32 pin) :
        gpioHandle(port),
        pin(pin)
    {
        gpioHandle.configure(hal::gpio::mode::out, pin);
    }

    void write()
    {
        gpioHandle.setPin(pin);
    }

private:
    hal::gpio gpioHandle;
    u32 pin;
};

} /* end of namespace drv */

#endif /* _CPPSZ_DRV_LED_H_ */
