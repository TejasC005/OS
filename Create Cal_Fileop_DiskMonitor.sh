#!/bin/bash


/*************** 1. SIMPLE CALCULATOR ****************/

echo "----- SIMPLE CALCULATOR -----"

read -p "Enter first number: " n1
read -p "Enter second number: " n2
read -p "Enter operation (+, -, *, /): " op

echo "Result: $(echo "scale=2; $n1 $op $n2" | bc)"


/*************** 2. DISK MONITORING ****************/

echo ""
echo "----- DISK MONITORING -----"

THRESHOLD=80

USAGE=$(df -h / | awk 'NR==2 {gsub("%",""); print $5}')

if [ "$USAGE" -ge "$THRESHOLD" ]; then
    echo "WARNING: Disk usage is at ${USAGE}%"
    # mail -s "Disk Alert" user@localhost
else
    echo "Disk usage is normal: ${USAGE}%"
fi


/*************** 3. FILE OPERATIONS ****************/

echo ""
echo "----- FILE OPERATIONS -----"

while true
do
    echo ""
    echo "1. Create File"
    echo "2. Delete File"
    echo "3. Copy File"
    echo "4. List Files"
    echo "5. Exit"

    read -p "Enter choice: " choice

    case $choice in

        1)
            read -p "Enter filename: " f
            touch "$f"
            echo "File created"
            ;;

        2)
            read -p "Enter filename: " f
            rm "$f"
            echo "File deleted"
            ;;

        3)
            read -p "Source file: " s
            read -p "Destination file: " d
            cp "$s" "$d"
            echo "File copied"
            ;;

        4)
            ls -lh
            ;;

        5)
            echo "Exiting..."
            break
            ;;

        *)
            echo "Invalid choice"
            ;;
    esac
done
