import java.lang.Math;
public class out{ 

public static double sum(Integer id3 , double id2) {
double c;
id2 =  2.000000 ;
id3 =  9 ;
c = Math.abs(id2 - id3);
 return c;
}
public static double sum1(Integer id31 , double id21) {
double c1;
id21 =  2.000000 ;
id31 =  9 ;
c1 = Math.abs(id21 - id31);
 return c1;
}
public static void main(String args[]){
double d;
d = sum( 56  ,  34.000000 );

if( d <  34 ) {
System.out.println(d);
 } else if(d ==  35 ) {
System.out.println( 35 );
} else {
System.out.println( 52 );
};
Integer i;
i =  2 ;
while (i <  45 ) {
System.out.println(i);
i = i +  1 ;
 };
}
}