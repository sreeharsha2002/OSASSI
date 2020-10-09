SHELL:

N.V.Sree Harsha Reddy 2019101040 CSE

HOW TO RUN:

1. Open the folder containing files in terminal
2. Run make
3. Run ./a.out
The operating_System_Shell will open up!
The shell takes the directory it is present in as the home of the shell as per requirements.

BUILT-IN-COMMANDS:

cd :
It changes the directory. It takes ~ as the folder that contains the executable. It takes relative paths also. Usage cd< path name >.

ls :
It lists files in the format accorning to flags.The flags -al -a -la -l -aaal -laa -lllaa etc. Usage: ls < flags > < files >. Options can come between arguments also. 

pwd :
It displays the present working directory

pinfo :
It executes the pinfo command mentioned in Assignment pdf. Usage: pinfo < pid1 > < pid2 > ...
If no pid is given then it shows the pinfo of shell.

echo :
It executes echo command. It does not implement "" '' $ etc. But handles whitespaces and tabs as required.

nightswatch :
BONUS 1 ! : Usage : nightswatch -n < time interval > < command >
It executes the command every time interval seconds mentioned by the option.
The commands can be:
1. interrupt : It shows the CPU interrupts as said in Assignment PDF.
2. newborn : It shows the latest process pid that was made on the system.
Press q to exit the loop.

history
BONUS 2 !: Usage : history < num >
By default it shows max 10. But if num is given it shows the last num commands if num commands are available or last available. If num is > 20, It defaults to 20.
If the last two commands are same then history take them as same and it stores as one command. 
It also includes the current command that executed like in real terminal. The history is stored in a file called history.txt in the folder that the files exist.

FILES INCLUDED:

main.c:
It has the main function and the loop that executes the shell. It also has the prompt printing.It also gets the command as input and calls the comm fn which will excecute in comm.c to handle the inputs.it has gotohistory() fn it handle the input or command given to history.txt in the executable folder.

comm.c:
It has the fuction calls to execute commands like :
1.gotocd():handle input regarding cd command
2.gotols(): handle input regarding ls command
3.gotopwd():hadle the input regarding pwd command
4.gotonight():handle the input regarding nightswatch command;
5.gotofgbg():handle the input to run on backgroung or foreground.
6.echo,pinfo,history commands are handled there it self not calling a function.

substring.c:
It has the funtions like:
1.substring() to make a substring from a string.
2.gotocd() : handle input regarding cd command regarging to the passing parameters.
3.gotopwd():hadle the input regarding pwd command
4.max():returns max fn.

prompt.c:
It will handle how to print the prompt with ~ representing the folder where we are executing and other things.

ls.c:
It has funtions like:
1.perm():returns the permissions of the file.
2.gotols(): handle input regarding ls command and prints the output according to flags.

fgbg.c
it has funtions like:
1.gotofgbg():handle the input to run on backgroung or foreground. as parameters passed from comm.c seperates the process which has to run in fg and bg to coreesponding fns.
2.gotofg():after seperation of process the processes which has to be run on foreground will to this function and execute appropriately.
3.gotofg():after seperation of process the processes which has to be run on background will to this function and execute appropriately. and in this function the signal fn will be called when there is signal interrupt. and we have to print which has exited so there is handler fn which outputs tp stderr for which process ha exited according to signal.
4.myhand():it is handler function of signal fn to handle how to print the exited ones.

nigtw.c :
it has funtions like:
1.gotonight():handle the input regarding nightswatch command and parameters passed from comm.c

history.c :
it has functions like:
1.gotohistory():It will handle the commands given to history.txt file and excecuting of history command is in comm.c itself; in this we create the history.txt file to store permanently that means if we go out our shell and came back it has to have the previous commands also as real history command does.

headers.h:
it has all the list of inbuilt headers that we use for this programs.

All the other headers are should be include to use their corresponding .c files.

makefile has all my .c files to compile at once.

After the backgroung process is terminated I am printing it has printed normally or abnormally so after printing that press ENTER to make the prompt visible if you donot give the ENTER also it takes input the prompt will come after pressing ENTER because of stderr printing.

