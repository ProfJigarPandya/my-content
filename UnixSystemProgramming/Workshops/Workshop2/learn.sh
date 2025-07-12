#!/bin/sh
echo "Menu: Press 1 to learn about ls. \nPress 2 to learn about man. \nPress 3 to learn about who. \nPress 4 to learn about exit."
read choice
case $choice in
1)
	echo "To display file attributes press ls -l"
	ls -l
	;;
2)	
	echo "To use manual pages use command man man"
	man man
	;;
3)
	echo "To show who are logged on to system with details use who -Hu"
	who -Hu
	;;
4)
	echo "Exit with message code 1 about not helpful application."
	exit 1
	;;
esac

echo "Thank you."
exit 0
