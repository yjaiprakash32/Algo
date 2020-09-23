package com.company;

import java.awt.desktop.SystemSleepEvent;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;
import java.util.Stack;

public class textEditor {

    public static void main(String[] args) {
        Stack<String> undo = new Stack<String>();
        Stack<String> redo = new Stack<String>();
        StringBuilder str = new StringBuilder();
        Scanner sc = new Scanner(System.in);
        str.append("");
        StringBuilder clipBoard = new StringBuilder();
        clipBoard.append("");
        int cursor= 0;
        String cmd;
        while(true){
            cmd= sc.nextLine().toUpperCase().trim();
            switch(cmd){
                case "EXIT":
                    System.exit(0);
                    break;
                case "PRINT":
                    System.out.println(str);
                    break;
                case "PRINT_CURSOR":
                    System.out.println(cursor);
                    break;
                case "INSERT":
                    undo.push(str.toString());
                    String chr = sc.nextLine();
                    str.append(chr,cursor,chr.length());
                    break;
                case "SEEK":
                    int val = sc.nextInt();
                    sc.nextLine();
                    if(val>str.length()){
                        System.out.println("REPEAT COMMAND AND ENTER A VALID LENGTH ");
                    }
                    else {
                        if (val != -1)
                            cursor = val;
                        else
                            cursor = str.length();
                    }
                    break;
                case "DELETE":
                    try {
                        int delVal = sc.nextInt();
                        sc.nextLine();
                        undo.push(str.toString());
                        if (delVal > str.length()) {
                            System.out.println("NOTHING DELETED AS CURSOR OUT OF RANGE ");
                        } else {
                            if (delVal == 1)
                                str.delete(cursor, cursor + 1);
                            else {
                                str.delete(cursor - 1, cursor - 1);
                                cursor = cursor - 1;
                            }
                        }
                    }
                    catch (Exception e){
                        System.out.println("REDO COMMAND AND ENTER CORRECT VALUE ie 1 or -1");
                    }
                    break;
                case "COPY":
                    System.out.println("Enter From: ");
                    int copyFrom = sc.nextInt();
                    System.out.println("Enter To: ");
                    int copyTo = sc.nextInt();
                    sc.nextLine();
                    if(copyFrom<0 || copyTo>str.length()){
                        System.out.println("REPEAT COMMAND AND ENTER CORRECT VALUES ");
                    }
                    else {
                        clipBoard.append(str, copyFrom, copyTo);
                    }
                    break;
                case "PRINT_CLIPBOARD":
                    System.out.println(clipBoard);
                    break;
                case "OPEN":
                    String fName = sc.nextLine();
                    str.delete(0,str.length());
                    try(Scanner scanner = new Scanner(new File(fName),"UTF-8")){
                        String txt= scanner.nextLine();
                        str.append(txt,0,txt.length());
                        cursor = str.length();
                        clipBoard.delete(0,clipBoard.length());
                    }
                    catch(Exception e){}
                    break;
                case "SAVE":
                    String fileName = sc.nextLine();
                    try{
                        FileWriter fw = new FileWriter(new File(fileName));
                        fw.write(str.toString());
                        fw.close();
                    }
                    catch (Exception e){}
                    break;
                case "CUT":
                    System.out.println("Enter from: ");
                    int n = sc.nextInt();
                    System.out.println("Enter to: ");
                    int m = sc.nextInt();
                    sc.nextLine();
                    undo.push(str.toString());
                    if(n<0||m>str.length())
                        System.out.println("REPEAT COMMAND AND ENTER CORRECT VALUES");
                    else{
                        clipBoard.append(str,n,m);
                        str.delete(n,m+1);
                        cursor = str.length();
                    }
                    break;
                case "PASTE":
                    int l= sc.nextInt();
                    sc.nextLine();
                    undo.push(str.toString());
                    str.insert(l,clipBoard);
                    cursor =l+ clipBoard.length();
                    break;
                case "UNDO":
                    try {
                        int len = str.length();
                        redo.push(str.toString());
                        str.replace(0, len, undo.pop());
                    }
                    catch (Exception e){
                        System.out.println("NO MORE OPERATIONS POSSIBLE!");
                    }
                    break;
                case "REDO":
                    try {
                        int lt = str.length();
                        str.replace(0, lt, redo.pop());
                    }
                    catch (Exception e){
                        System.out.println("NO MORE OPERATIONS POSSIBLE!");
                    }
                    break;
            }
        }
    }
}
