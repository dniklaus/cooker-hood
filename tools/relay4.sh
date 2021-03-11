#/bin/bash
usbser=$(ls /dev/ttyACM* | awk {'print $1'})
stty -F ${usbser} cs8 9600 -hupcl -crtscts eol 0x0D eol2 0x0A

echo "" > ${usbser}
echo "dbg relay4 pulse" > ${usbser}
echo "" > ${usbser}
