public class Circle extends BaseShape{
	public double r;
    public Circle(double a){
    	r = a;
    	id = counter;
    	counter = counter +1;
    }
    protected void calculate(){ 
    	length = 2*r*3.14;
    	area = 3.14*r*r;
    }
}
