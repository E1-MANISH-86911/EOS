#14. Write a shell script to display only executable files of current directory.
#!/bin/bash
for i in *
do
    if [ -x "$i" ] && [ ! -d "$i" ]
    then
        echo "$i"
    fi
done

