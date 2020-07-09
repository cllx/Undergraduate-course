public class EquicruralLader extends BaseShape{
	double above, botton, height, yao;
    public EquicruralLader(double a,double b,double c){
    	botton = b;
    	yao = a;
    	above = c;
    	id = counter;
    	counter = counter +1;
    }
	protected void calculate(){
    	length = botton + 2*yao + above;
    	height = Math.sqrt(yao*yao - ((above - botton)/2)*((above - botton)/2));
    	area = (botton + above)*height/2; 
    }
	public boolean validate(){
	    double m=yao, n=yao, p=Math.abs(botton-above);
	    if((m+n>p && n+p>m && p+m>n) && (m==n) )  //判定是否合法梯形
	         return true;
	    else
	         return false;
    }
}
