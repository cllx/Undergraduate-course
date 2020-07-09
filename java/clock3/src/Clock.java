import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.*;

import java.util.*; 


public class Clock extends JPanel implements Runnable{

	public static final JPanel q = new JPanel();//���ڵڶ���ǩҳ��ʱ����ʾ����
	int y,m,d,h,mi,s; 
	JLabel clock=new JLabel();
	
	JLabel lab3=new JLabel("ʱ");
	JLabel lab4=new JLabel("��");
	JLabel lab5=new JLabel("��");
	JLabel lab1=new JLabel ("����ʱ��");

	Calendar cal;//���ڻ�ȡ����ʱ��ı���
	JTextField[] time=new JTextField[3];//ʱ����ʾ�����е�ˢ������
    public Clock()
	{
    	lab1.setForeground(Color.WHITE);//����ǰ��ɫ���˴�Ϊ������ɫ��
    	lab3.setForeground(Color.WHITE);
    	lab4.setForeground(Color.WHITE);
    	lab5.setForeground(Color.WHITE);
    	for(int f=0;f<3;f++)
    	{
    		time[f]=new JTextField(4);
    		time[f].setSize(20,30);
    	}
		setBounds(100,100,410,410);//���ڴ�С
		
		
        setLayout(new BorderLayout());//�����趨
       //���������
        add(clock,BorderLayout.SOUTH);
        q.add(lab1);q.add(time[0]);q.add(lab3);q.add(time[1]);q.add(lab4);q.add(time[2]);q.add(lab5);
        
     }
	public String toString()//����������ʾ����ʱ��
	{
		return String.format("%d year,%d month,%d day\n"+"%d :%d :%d ",y,m+1,d,h,mi,s);
	}
    public void run()//�̲߳���
	{
	     while(true)
	        {
	        try{
	        	//��ȡ����ʱ��
	        	cal=Calendar.getInstance(); 
	        	y=cal.get(Calendar.YEAR); 
		          m=cal.get(Calendar.MONTH);
		            d=cal.get(Calendar.DATE); 
		            h=cal.get(Calendar.HOUR_OF_DAY); 
		            mi=cal.get(Calendar.MINUTE); 
		            s=cal.get(Calendar.SECOND);
		            clock.setForeground(Color.WHITE);
		            clock.setText(toString());
		            time[0].setText(new String().valueOf(h));//��int��ת��ΪString���ͣ���ȡ��ˢ��ʱ��
	        	     time[1].setText(new String().valueOf(mi));
	        	     time[2].setText(new String().valueOf(s));
		            repaint();//��ָ���ÿ��һ��ˢ��һ��
					Thread.sleep(1000);//�ӳ�ʱ��Ϊ1�룬���߳�ÿ��һ�����һ��
			    }
	        catch(InterruptedException e){//�߳��г����쳣�Ĵ���
					e.printStackTrace();}
	      
	       }
	}
	public void paintComponent(Graphics g)
	{
	    super.paintComponent(g);
		//�˴�Ϊ����ͼ����
		try{
	        BufferedImage img = ImageIO.read(this.getClass().getResource("clock.png"));
	        g.drawImage(img, 0, 0, this.getWidth(), this.getHeight(), null);
	      } catch (IOException e) 
               {
                  e.printStackTrace();
                }
        //����Ϊ���ӻ���
		Point center=new Point(410/2-8,410/2-15);//��������
		int secondLength=(int)(410*0.4);//ָ�볤��
		int minuteLength=(int)(secondLength*0.8);
		int hourLength=(int)(minuteLength*0.8);
		int sX=center.x+(int)(secondLength*Math.sin(s*2*Math.PI/60.0));//ָ��λ���趨
		int sY=center.y-(int)(secondLength*Math.cos(s*2*Math.PI/60.0));
		int miX=center.x+(int)(minuteLength*Math.sin(mi*2*Math.PI/60.0));
		int miY=center.y-(int)(minuteLength*Math.cos(mi*2*Math.PI/60.0));
		int hX=center.x+(int)(hourLength*Math.sin((mi/60.0+h)*Math.PI/6.0));
		int hY=center.y-(int)(hourLength*Math.cos((mi/60.0+h)*Math.PI/6.0));
        g.setColor(Color.RED);//ָ����ɫ�趨
        g.drawLine(center.x,center.y,hX,hY);//����ָ��
        g.setColor(Color.MAGENTA);
        g.drawLine(center.x,center.y,miX,miY);
        g.setColor(Color.BLUE);
        g.drawLine(center.x,center.y,sX,sY);
      }

}
