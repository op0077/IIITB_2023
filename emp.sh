echo " Menu  : "
touch emp.txt
while true; do
    echo "menu:"
    echo "1) list all .sh files"
    echo "2) Search in folder"
    echo "3) create emp record"
    echo "4) show records"
    echo "5) search emp records" 
    echo "6) sort records"
    echo "7) exit"
    read choice
    case $choice in
        1)
            clear
            ls -l *.sh
            ;;
        2)
            clear
            read f
            ls -l | grep $f
            ;;
        3) 
            clear
            echo "enter name,id and number"
            read name
            echo $name>>emp.txt
            echo "showing emp.txt ..."
            cat emp.txt
            ;;

        4)
            clear
            cat emp.txt
            ;;
        5)
            clear
            echo "entere word or letter to search"
            read word
            cat emp.txt | grep $word
            ;;
        6)  
            clear
            sort emp.txt
            ;;
        7)
            clear
            echo "leaving ..."
            break
            ;;
    esac

done
