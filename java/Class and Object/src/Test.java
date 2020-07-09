import java.util.ArrayList;
import java.util.Collections;  
import java.util.Comparator;
public class Test{
	public static void main(String[] args){
		Shape s1 = new Trangle(6,8,10);
        Shape s2 = new Trangle(1,2,3);
        //��һ������Ϊ�ף��ڶ�������Ϊ��
        Shape s3 = new EquicruralTrangle(12,12);
        Shape s4 = new EquicruralTrangle(10,5);                 
        Shape s5 = new Lader(1,15,12,15,13);
        Shape s6 = new Lader(1,10,4,4,5);
        //��һ����Ϊ�ϵף��ڶ�����Ϊ�µף���������Ϊ��
        Shape s7 = new EquicruralLader(2,8,5);                           
        Shape s8 = new EquicruralLader(2,16,5);
        Shape s9 = new Circle(3);
        Shape s10 = new Circle(5);
        ArrayList<Shape> list = new ArrayList<Shape>();
        System.out.println("���˲��Ϸ�����״:");
        if(!s1.validate())
        	System.out.println("           1�Ŷ����ǲ��Ϸ���");
        else{
        	s1.init();
        	list.add(s1);
        }
        if(!s2.validate())
        	System.out.println("           2�Ŷ����ǲ��Ϸ���");
        else{
        	s2.init();
        	list.add(s2);
        }
        if(!s3.validate())
        	System.out.println("           3�Ŷ����ǲ��Ϸ���");
        else{
        	s3.init();
        	list.add(s3);
        }
        if(!s4.validate())
        	System.out.println("           4�Ŷ����ǲ��Ϸ���");
        else{
        	s4.init();
        	list.add(s4);
        }
        if(!s5.validate())
        	System.out.println("           5�Ŷ����ǲ��Ϸ���");
        else{
        	s5.init();
        	list.add(s5);
        }
        if(!s6.validate())
        	System.out.println("           6�Ŷ����ǲ��Ϸ���");
        else{
        	s6.init();
        	list.add(s6);
        }
        if(!s7.validate())
        	System.out.println("           7�Ŷ����ǲ��Ϸ���");
        else{
        	s7.init();
        	list.add(s7);
        }
        if(!s8.validate())
        	System.out.println("           8�Ŷ����ǲ��Ϸ���");
        else{
        	s8.init();
        	list.add(s8);
        }
        if(!s9.validate())
        	System.out.println("           9�Ŷ����ǲ��Ϸ���");
        else{
        	s9.init();
        	list.add(s9);
        }
        if(!s10.validate())
        	System.out.println("           10�Ŷ����ǲ��Ϸ���");
        else{
        	s10.init();
        	list.add(s10);
        }
        System.out.println("���ܳ�����:");
        /*
        for(Shape s:list){
        	System.out.print(    s.getLength());
        }
        */
        /*
        for(int i = 0;i < list.size();i++){
        	for(int j = i +1 ;j<list.size();j++){
	        	if(list.get(i).getLength() < list.get(j).getLength()){
	        		Shape temp = list.get(i);
	        		list.get(i) = list.get(j);
	        		list.get(j) = temp;
	        	}
        	}
        }
        */
        Collections.sort(list,new Comparator<Shape>(){
        	public int compare(Shape o1, Shape o2) {
        		if(o1.getLength() > o2.getLength()){  
                    return 1;  
                }  
                if(o1.getLength() == o2.getLength()){  
                    return 0;  
                }
                return -1;
        	}
        });
        for(int i = 0;i < list.size();i++){
        	System.out.print(list.get(i).getId()+"       ");
        }
        System.out.println();
        System.out.println("���������:");
        Collections.sort(list,new Comparator<Shape>(){
        	public int compare(Shape o1, Shape o2) {
        		if(o1.getArea() > o2.getArea()){  
                    return 1;  
                }  
                if(o1.getArea() == o2.getArea()){  
                    return 0;  
                }
                return -1;
        	}
        });
        for(int i = 0;i < list.size();i++){
        	System.out.print(list.get(i).getId()+"       ");
        }
	}
}
