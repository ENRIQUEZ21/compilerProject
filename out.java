import java.lang.Math;
public class out{ 

public static double myabs(Integer id3 , double id2) {
double c;
id2 =  2.000000 ;
id3 =  9 ;
c = Math.abs(id2 - id3);
return c;
}
public static double myexp(Integer id3 , double id2) {
double c;
id2 =  45.000000 ;
id3 =  67 ;
c = Math.exp(id2 - id3);
return c;
}
public static void main(String args[]){
double d;
d =  1.000000 ;

if( d <  34 ) {
d = myabs( 12  ,  10.120000 );
Integer i4;
System.out.println(d);
 } else if(d ==  35 ) {
d = myabs( 35  ,  10.130000 );
System.out.println(d);
} else {
d = myexp( 30  ,  20.200000 );
System.out.println(d);
};
Integer i4;
Integer i;
double o;
o =  9.890000 ;
i =  9 ;
while (i <  45 ) {
double l;
l = myexp( 31  ,  45.780000 );
o = o + l;
System.out.println(o);
System.out.println(i);
i = i +  1 ;
 };
System.out.println("The sum of all exp is : ");
System.out.println(o);
}
}