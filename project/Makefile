# makfile configuration
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all:lcdToy.elf lcd_testing.elf

#additional rules for files
lcdToy.elf: ${COMMON_OBJECTS} wakedemo.o wdt_handler.o switch_interrupt_handler-s.o switch-init-s.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd 

lcd_testing.elf: ${COMMON_OBJECTS} lcd_testing.o maze_draw.o maze_data.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd

load: wakedemo.elf
	msp430loader.sh $^

load_lcd_t: lcd_testing.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf *~
