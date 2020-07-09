import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.*;

import java.util.*; 


public class Clock extends JPanel implements Runnable{

	public static final JPanel q = new JPanel();//用于第二标签页的时间显示区域
	int y,m,d,h,mi,s; 
	JLabel clock=new JLabel();
	
	JLabel lab3=new JLabel("时");
	JLabel lab4=new JLabel("分");
	JLabel lab5=new JLabel("秒");
	JLabel lab1=new JLabel ("现在时间");

	Calendar cal;//用于获取本地时间的变量
	JTextField[] time=new JTextField[3];//时间显示区域中的刷新区域
    public Clock()
	{
    	lab1.setForeground(Color.WHITE);//设置前景色（此处为字体颜色）
    	lab3.setForeground(Color.WHITE);
    	lab4.setForeground(Color.WHITE);
    	lab5.setForeground(Color.WHITE);
    	for(int f=0;f<3;f++)
    	{
    		time[f]=new JTextField(4);
    		time[f].setSize(20,30);
    	}
		setBounds(100,100,410,410);//窗口大小
		
		
        setLayout(new BorderLayout());//布局设定
       //添加相关组件
        add(clock,BorderLayout.SOUTH);
        q.add(lab1);q.add(time[0]);q.add(lab3);q.add(time[1]);q.add(lab4);q.add(time[2]);q.add(lab5);
        
     }
	public String toString()//用于下面显示本地时间
	{
		return String.format("%d year,%d month,%d day\n"+"%d :%d :%d ",y,m+1,d,h,mi,s);
	}
    public void run()//线程部分
	{
	     while(true)
	        {
	        try{
	        	//获取本地时间
	        	cal=Calendar.getInstance(); 
	        	y=cal.get(Calendar.YEAR); 
		          m=cal.get(Calendar.MONTH);
		            d=cal.get(Calendar.DATE); 
		            h=cal.get(Calendar.HOUR_OF_DAY); 
		            mi=cal.get(Calendar.MINUTE); 
		            s=cal.get(Calendar.SECOND);
		            clock.setForeground(Color.WHITE);
		            clock.setText(toString());
		            time[0].setText(new String().valueOf(h));//将int型转换为String类型，获取并刷新时间
	        	     time[1].setText(new String().valueOf(mi));
	        	     time[2].setText(new String().valueOf(s));
		            repaint();//令指针等每隔一秒刷新一次
					Thread.sleep(1000);//延迟时间为1秒，令线程每隔一秒调用一次
			    }
	        catch(InterruptedException e){//线程中出现异常的处理
					e.printStackTrace();}
	      
	       }
	}
	public void paintComponent(Graphics g)
	{
	    super.paintComponent(g);
		//此处为背景图绘制
		try{
	        BufferedImage img = ImageIO.read(this.getClass().getResource("clock.png"));
	        g.drawImage(img, 0, 0, this.getWidth(), this.getHeight(), null);
	      } catch (IOException e) 
               {
                  e.printStackTrace();
                }
        //以下为闹钟绘制
		Point center=new Point(410/2-8,410/2-15);//表盘中心
		int secondLength=(int)(410*0.4);//指针长度
		int minuteLength=(int)(secondLength*0.8);
		int hourLength=(int)(minuteLength*0.8);
		int sX=center.x+(int)(secondLength*Math.sin(s*2*Math.PI/60.0));//指针位置设定
		int sY=center.y-(int)(secondLength*Math.cos(s*2*Math.PI/60.0));
		int miX=center.x+(int)(minuteLength*Math.sin(mi*2*Math.PI/60.0));
		int miY=center.y-(int)(minuteLength*Math.cos(mi*2*Math.PI/60.0));
		int hX=center.x+(int)(hourLength*Math.sin((mi/60.0+h)*Math.PI/6.0));
		int hY=center.y-(int)(hourLength*Math.cos((mi/60.0+h)*Math.PI/6.0));
        g.setColor(Color.RED);//指针颜色设定
        g.drawLine(center.x,center.y,hX,hY);//绘制指针
        g.setColor(Color.MAGENTA);
        g.drawLine(center.x,center.y,miX,miY);
        g.setColor(Color.BLUE);
        g.drawLine(center.x,center.y,sX,sY);
      }

}
