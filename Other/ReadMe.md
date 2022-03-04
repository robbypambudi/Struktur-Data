
# Petugas Rangkaian Kereta Api
## Deskripsi Soal

## Code 
- Or Visit 
```
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution{
    
    static class Gerbong {
        String nama;
        Gerbong next;

        Gerbong(){
        }
        void setGerbong(String nama){
            this.nama = nama;
        }
        String getGerbong(){
            return nama;
        }
        void setNext(Gerbong next){
            this.next = next;
        }
        Gerbong getNext(){
            return next;
        }
    }
    static class Kereta{
        String NamaKereta;
        Gerbong kontainer;
        
        Kereta(){
            kontainer = new Gerbong();
        }
        Gerbong getGerbong(){
            return kontainer;
        }
        
        void setNamaKereta(String nama){
            this.NamaKereta = nama;
        }
        String getNamaKereta(){
            return NamaKereta;
        }
        
    }

    

    public static void pushKereta(Kereta baru, String nama, String [] gerbong){
        baru.setNamaKereta(nama);
        Gerbong g = baru.getGerbong();

        for(int i = 0; i < gerbong.length; i++){
            Gerbong temp = new Gerbong();
            if (i == 0){
                g.setGerbong(gerbong[i]);
                g.setNext(temp);
                g = g.getNext();
            }
            else {
                g.setGerbong(gerbong[i]);
                g.setNext(temp);
                g = g.getNext();
            }            
        }

    } 

    public static void printKereta(Kereta k){
        Gerbong g = k.getGerbong();
        System.out.println(k.getNamaKereta());
        while(g != null){
            if(g.next.getGerbong() == null){
                System.out.print(g.getGerbong());
                break;
            }
            System.out.print(g.getGerbong()+"-");
            g = g.next;
        }
        
    }
        
    

    public static void main(String[] args){
        Kereta kereta = new Kereta();

        Scanner in = new Scanner(System.in);
        
        String NamaKereta = in.nextLine();
        String Gerbong = in.nextLine();

        String[] arrGerbong = Gerbong.split("-");
        pushKereta(kereta,NamaKereta, arrGerbong);
        printKereta(kereta);

    }

}
```