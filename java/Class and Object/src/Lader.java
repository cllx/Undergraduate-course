class Lader extends BaseShape{  
    double above, botton, height, leftSide, rightSide;
    public Lader(double a,double b,double c,double d,double e){
    	botton = a;
    	leftSide = b;
    	above = c;
    	rightSide = d;
    	height = e;
    	id = counter;
    	counter = counter +1;
    }
    protected void calculate(){
    	length = botton + leftSide + above + rightSide;
    	area = (botton + above)*height/2; 
    }
    public boolean validate(){
	    double m=leftSide, n=rightSide, p=Math.abs(botton-above);
	    if(m+n>p && n+p>m && p+m>n)   //判定是否合法梯形
	         return true;
	    else
	         return false;
    }
}


