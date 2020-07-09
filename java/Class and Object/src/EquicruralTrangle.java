public class EquicruralTrangle extends BaseShape{
	double botton, yao;
    public EquicruralTrangle(double a,double b){
    	botton = a;
    	yao = b;
    	id = counter;
    	counter = counter +1;
    }
	protected void calculate(){ 
    	length = botton + 2*yao;
    	area = Math.sqrt((length/2)*(length/2-botton)*(length/2-yao)*(length/2-yao));
    }
    public boolean validate(){
	    if(yao+yao<=botton)   //�ж��Ƿ�Ϸ�������
	         return false;
	    else
	         return true;
    }
}
