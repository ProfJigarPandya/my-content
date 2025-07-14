[jpandya@JMP shellscripts]$ cat reversen.sh
#Shell script to reverse a number
echo "Enter a number to be reversed";
read n
$res
len=`expr $n : '.*'`

if [ $len -eq 1 ]
then
        echo "Reversed number is $n"
else
        modulo=`expr $n % 10`
        res=$modulo
        n=`expr $n / 10`

        while [ $n -gt 0 ]
        do
                modulo=`expr $n % 10`
                n=`expr $n / 10`
                res=`expr $res \* 10 + $modulo`
        done
        echo "Reversed number is $res"
fi

echo "Have a nice day!"
[jpandya@JMP shellscripts]$ ./reversen.sh 
Enter a number to be reversed
123
Reversed number is 321
Have a nice day!
[jpandya@JMP shellscripts]$ ./reversen.sh 
Enter a number to be reversed
1
Reversed number is 1
Have a nice day!
[jpandya@JMP shellscripts]$ ./reversen.sh 
Enter a number to be reversed
0
Reversed number is 0
Have a nice day!
[jpandya@JMP shellscripts]$ ./reversen.sh 
Enter a number to be reversed
1200
Reversed number is 21
Have a nice day!
[jpandya@JMP shellscripts]$ 



[jpandya@JMP shellscripts]$ cat reversestr.sh 
#!/bin/bash
# Reversing a string using expr

echo "Enter String"
read str

if [ -z $str ]
then
        echo "No input. Try again later."
        exit 1
else
        echo "You entered $str"
        len=`expr $str : ".*"`

        echo -e "Reversed string is \c"
        for(( count=0; count<$len ; count++))
        do
                echo -e `expr "$str" : '.*\(.\)'`"\c"
                str=`expr "$str" : '\(.*\).'`
        done
        echo
fi
echo "Have a nice day."
exit 0
[jpandya@JMP shellscripts]$ ./reversestr.sh 
Enter String
hithere
You entered hithere
Reversed string is erehtih
Have a nice day.
[jpandya@JMP shellscripts]$ ./reversestr.sh 
Enter String
h
You entered h
Reversed string is h
Have a nice day.
[jpandya@JMP shellscripts]$ ./reversestr.sh 
Enter String

No input. Try again later.
[jpandya@JMP shellscripts]$ 



#/bin/bash
# Program to demo trap interrupt handling in shell script.
# This program locks the screen with user confirmed password. 
#Signal Name	Signal Number	Description
#SIGHUP		1		Hang up detected on controlling terminal or death of controlling process
#SIGINT		2		Issued if the user sends an interrupt signal (Ctrl + C).
#SIGQUIT	3		Issued if the user sends a quit signal (Ctrl + D).
#SIGFPE		8		Issued if an illegal mathematical operation is attempted
#SIGKILL	9		If a process gets this signal it must quit immediately and will not perform any clean-up operations
#SIGALRM	14		Alarm Clock signal (used for timers)
#SIGTERM	15		Software termination signal (sent by kill by default).

#[jpandya@JMP shellscripts]$ kill -l
# 1) SIGHUP       2) SIGINT       3) SIGQUIT      4) SIGILL
# 5) SIGTRAP      6) SIGABRT      7) SIGBUS       8) SIGFPE
# 9) SIGKILL     10) SIGUSR1     11) SIGSEGV     12) SIGUSR2
#13) SIGPIPE     14) SIGALRM     15) SIGTERM     16) SIGSTKFLT
#17) SIGCHLD     18) SIGCONT     19) SIGSTOP     20) SIGTSTP
#21) SIGTTIN     22) SIGTTOU     23) SIGURG      24) SIGXCPU
#25) SIGXFSZ     26) SIGVTALRM   27) SIGPROF     28) SIGWINCH
#29) SIGIO       30) SIGPWR      31) SIGSYS      34) SIGRTMIN
#35) SIGRTMIN+1  36) SIGRTMIN+2  37) SIGRTMIN+3  38) SIGRTMIN+4
#39) SIGRTMIN+5  40) SIGRTMIN+6  41) SIGRTMIN+7  42) SIGRTMIN+8
#43) SIGRTMIN+9  44) SIGRTMIN+10 45) SIGRTMIN+11 46) SIGRTMIN+12
#47) SIGRTMIN+13 48) SIGRTMIN+14 49) SIGRTMIN+15 50) SIGRTMAX-14
#51) SIGRTMAX-13 52) SIGRTMAX-12 53) SIGRTMAX-11 54) SIGRTMAX-10
#55) SIGRTMAX-9  56) SIGRTMAX-8  57) SIGRTMAX-7  58) SIGRTMAX-6
#59) SIGRTMAX-5  60) SIGRTMAX-4  61) SIGRTMAX-3  62) SIGRTMAX-2
#63) SIGRTMAX-1  64) SIGRTMAX



trap "echo 'this terminal is locked by '`whoami`" "`date` " 1 2 3 5 20
clear
echo -e "\nenter password to lock terminal:"
stty -echo
read keynew
stty echo
echo -e "\nconfirm password:"
stty -echo
read keyold
stty echo
if [ $keyold == $keynew ]
then
echo "terminal locked!"
	while [ 1 ]
	do
		echo "retype the password to unlock:"
		stty -echo
		read key
		if [ $key == $keynew ]
		then
			stty echo
			echo "terminal unlocked!"
			stty sane
		exit
		fi
		echo "invalid password!"
	done
else
	echo " passwords do not match!"
fi
stty sane


enter password to lock terminal:

confirm password:
terminal locked!
retype the password to unlock:
./terminallock.sh: line 51: [: =: unary operator expected
invalid password!
retype the password to unlock:
./terminallock.sh: line 51: [: =: unary operator expected
invalid password!
retype the password to unlock:
./terminallock.sh: line 51: [: =: unary operator expected
invalid password!
retype the password to unlock:
./terminallock.sh: line 51: [: =: unary operator expected
invalid password!
retype the password to unlock:
this terminal is locked by jpandya
this terminal is locked by jpandya
./terminallock.sh: line 51: [: =: unary operator expected
invalid password!
retype the password to unlock:
invalid password!
retype the password to unlock:
invalid password!
retype the password to unlock:
terminal unlocked!
[jpandya@JMP shellscripts]$ 




[jpandya@JMP shellscripts]$ ./ffact.sh 
Enter a number: 
5
5! = 120
[jpandya@JMP shellscripts]$ cat ffact.sh 
#!/bin/sh
# Program for finding factorial on n using function.
fac()
{
        if [ "$1" -gt 1 ]; then
                result=1
                for ((i=1;i<="$1";i++))
                do
                        result=`expr $result \* $i`
                done
                echo $result
        else
                echo 1
        fi
}

echo "Enter a number: "
read NUM
echo "$NUM! = `fac $NUM`"
[jpandya@JMP shellscripts]$ 
[jpandya@JMP shellscripts]$ cat ffact.sh 
#!/bin/sh
# Program for finding factorial on n using function.
fac()
{
        if [ "$1" -gt 1 ]; then
                result=1
                for ((i=1;i<="$1";i++))
                do
                        result=`expr $result \* $i`
                done
                echo $result
        else
                echo 1
        fi
}

echo "Enter a number: "
read NUM
echo "$NUM! = `fac $NUM`"
[jpandya@JMP shellscripts]$ ./ffact.sh 
Enter a number: 
7 
7! = 5040
[jpandya@JMP shellscripts]$ ./frfact.sh 
Enter a number: 
7
7! = 5040
[jpandya@JMP shellscripts]$ cat frfact.sh 
#!/bin/sh
# Finding factorial using recursion (function calling itself)
fac()
{
        if [ "$1" -gt 1 ]; then
                NEXT=`expr $1 - 1`
                REC=`fac $NEXT`
                PROD=`expr $1 \* $REC`
                echo $PROD
        else
                echo 1
        fi
}

echo "Enter a number: "
read NUM
echo "$NUM! = `fac $NUM`"
[jpandya@JMP shellscripts]$ 
