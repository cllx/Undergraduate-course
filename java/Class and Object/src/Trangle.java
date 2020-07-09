class Trangle extends BaseShape{  
    double botton, leftSide, rightSide;
    public Trangle(double a,double b,double c){
    	botton = a;
    	leftSide = b;
    	rightSide = c;
    	id = counter;
    	counter = counter +1;
    }
    protected void calculate(){
    	length = botton + leftSide + rightSide;
    	area = Math.sqrt((length/2)*(length/2-botton)*(length/2-rightSide)*(length/2-leftSide)); 
    }
    public boolean validate(){
	    if(leftSide+rightSide<=botton || botton+rightSide<=leftSide || leftSide+botton<=rightSide)   //�ж��Ƿ�Ϸ�������
	         return false;
	    else
	         return true;
    }
}


