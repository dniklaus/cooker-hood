#/bin/bash
usbser=$(ls /dev/ttyACM* | awk {'print $1'})
stty -F ${usbser} cs8 9600 -hupcl -crtscts eol 0x0D eol2 0x0A

echo "" > ${usbser}
echo "dbg lamp pulse" > ${usbser}
echo "" > ${usbser}
