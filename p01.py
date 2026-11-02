# file: p01.py
#
# revision history:
#   20260918: calibrated exact fahrenheit transfer function from empirical adc values
#

# define primary sensor and actuator loop handler
#
def on_forever():

    # read raw analog sensor value (0 - 1023) from pin 0
    #
    sensor_val = pins.analog_read_pin(AnalogPin.P0)

    # compute calibrated temperature in fahrenheit directly from raw adc counts
    #
    temp_f = ((sensor_val - 119) * 117) / 166 - 40

    # display rounded fahrenheit reading on microbit led matrix
    #
    basic.show_number(Math.round(temp_f))

    # evaluate discrete fahrenheit temperature ranges and set leds
    #
    if temp_f < 68:

        # cold range (< 68 f): turn on blue (pin 8), turn off others
        #
        pins.digital_write_pin(DigitalPin.P8, 1)
        pins.digital_write_pin(DigitalPin.P16, 0)
        pins.digital_write_pin(DigitalPin.P1, 0)

    elif temp_f >= 68 and temp_f < 86:

        # normal range (68 f - 85 f): turn on green (pin 16), turn off others
        #
        pins.digital_write_pin(DigitalPin.P8, 0)
        pins.digital_write_pin(DigitalPin.P16, 1)
        pins.digital_write_pin(DigitalPin.P1, 0)

    else:

        # hot range (>= 86 f): turn on red (pin 1), turn off others
        #
        pins.digital_write_pin(DigitalPin.P8, 0)
        pins.digital_write_pin(DigitalPin.P16, 0)
        pins.digital_write_pin(DigitalPin.P1, 1)

    # short delay between loop cycles
    #
    basic.pause(100)

# register recurring sensor execution loop
#
basic.forever(on_forever)

#
# end of file
