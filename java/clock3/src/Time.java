import java.awt.*;

import javax.swing.*;

import java.awt.event.*;
import java.util.*;
import java.applet.*;
import java.io.File;
import java.net.MalformedURLException;
import java.net.URI;
import java.net.URL;

public class Time extends JPanel implements Runnable,AudioClip{
	JTextField[] time=new JTextField[3];//闹钟设定的输入区域
	JComboBox box;//音乐选框
	String[] songs={"1.wav","2.wav","3.wav"};//歌曲名称列表
    JLabel lab1,lab2,lab6,lab7,lab8;//闹钟设定的文字区域
    JButton b1=new JButton(),b2=new JButton();//按钮
    JPanel[] p=new JPanel[2];//第二行的容器
   Clock c;//建立一个clock类的变量c，用以获取其中类变量q，充当时间显示区域
   Icon icon=new ImageIcon("button1.png");//按钮图标
	Icon icon1=new ImageIcon("button2.png");
	int h,mi,s,count=0,count1=0; //count、count1为控制变量，之后在线程中使用
	boolean flag=false,flag2=false;//旗帜变量，线程中使用
	String[] t=new String[3];//用于存储闹钟设定时间
	Calendar cal;//获取时间的变量
	//一下四行为音乐播放需使用的变量 
	File musicfile;
	 URI uri;
	 URL url;
	 AudioClip clip;
	 String song="1.wav";//默认初始音乐
	 Background back=new Background();//背景图
	public Time(Clock clock) throws MalformedURLException
	{
		
		back.setBounds(0,0,410,410);//背景大小设定		
		c=clock;//令c与主函中建立的clock类产生关联
		for(int i=0;i<3;i++)
		{
			time[i]=new JTextField(4);
			time[i].setSize(20,30);
		}

		
		lab6=new JLabel("时");
		lab7=new JLabel("分");
		lab8=new JLabel("秒");
		lab2=new JLabel ("响铃时间");
		lab6.setForeground(Color.WHITE);//前景色
		lab7.setForeground(Color.WHITE);
		lab8.setForeground(Color.WHITE);
		lab2.setForeground(Color.WHITE);

		b1.setBounds(150,0,40,27);//按钮位置及大小
	    b2.setBounds(200,0,40,27);
		b1.setIcon(icon);
		b2.setIcon(icon1);
		setLayout(new BorderLayout());
		b1.addActionListener(//为按钮添加侦听器
				new ActionListener()
				{
					public void actionPerformed(ActionEvent e)
					{
						
							flag=true;//旗帜变量flag用于控制是否开启闹钟功能true为开启
                        
						for(int i=0;i<3;i++)
						{
							t[i]=time[i].getText();//获取设定的时间
						  
						    	
						}
						
						
					}
					
				});
		b2.addActionListener(
				new ActionListener()
				{
					
					public void actionPerformed(ActionEvent e)
					{
						try
						{
						flag=false;
					    clip.stop();
					    flag2=false;
					    count=0;
					    
					    }
						catch(NullPointerException e1)//获取异常
						{
							JOptionPane.showMessageDialog(null,"闹钟设定错误！");//异常弹框
						}

					}
					
				});
		box=new JComboBox(songs);//选框内容
		box.setMaximumRowCount(3);//选框一次最多显示的行数
		
		box.addItemListener(//为选框加入监听器
				new ItemListener()
				{
				public void itemStateChanged(ItemEvent e)
				{
					if(e.getStateChange()==ItemEvent.SELECTED)
						song=new String().valueOf(e.getItem());//song重新赋值
				}} );
	
		for(int k=0;k<2;k++)
		{
			p[k]=new JPanel();
		}
		 p[1].setLayout(null);
		p[0].add(lab2);p[0].add(time[0]);p[0].add(lab6);p[0].add(time[1]);p[0].add(lab7);p[0].add(time[2]);p[0].add(lab8);p[0].add(box);
		p[1].add(b1);p[1].add(b2);
		back.setLayout(null);
		add(back);
		p[0].setOpaque(false);//设置p为透明背景，这样可以不会遮盖背景图
		p[1].setOpaque(false);
		p[0].setForeground(Color.WHITE);//前景色
		p[0].setBounds(0,35,410,30);
		p[1].setBounds(0,300,410,30);
		back.add(p[0]);
		
		back.add(p[1]);
		
		
	}
      public void Alarm() throws MalformedURLException, InterruptedException
   {
	    try
	    {
    	  int i = 0;
	     
    	  
    	  if(flag==true)
    	  {
    		  
    		  //判定是否执行响闹
    		   if(new Integer(t[0])==c.h)
    			  if(new Integer(t[1])==c.mi)
    				  if(new Integer(t[2])==c.s)
    				  {
    					  //与音乐文件关联（音乐文件不可为MP3、wma）
    					  musicfile=new File(song);
    						uri=musicfile.toURI();
    						url=uri.toURL(); 
    					  
    						
    					 clip=Applet.newAudioClip(url);
                        clip.play();
                        i=JOptionPane.showConfirmDialog(null, "起床了！","Alarm",JOptionPane.YES_NO_OPTION);//弹窗，再响选项
                        if(i==JOptionPane.YES_OPTION)//选择yes闹钟停止
            		    { 
            		       clip.stop();
                           flag2 = false;//flag2为闹钟再响旗帜变量
                           count = 0;//响闹时间控制变量
                           count1=0;//再响控制变量
                         }
                        if(i==JOptionPane.NO_OPTION)//选no暂时停止响闹
                        {
                        	clip.stop();
                        }
                        flag2 = true; //音乐播放时间控制变量
                  }
    		    
                 if(flag2)
                 { count++;count1++;}//时间控制变量，用于统计响闹时间与再响间隔
                 if(count == 180)//响闹满3分钟后停止
                 {
                    clip.stop();
                    flag2 = false;
                    count = 0;
                 }
                 if(count1==60)//每过一分钟再响一次
                 {
                	 clip.play();
                	 i=JOptionPane.showConfirmDialog(null, "起床了！","Alarm",JOptionPane.YES_NO_OPTION);
                     if(i==JOptionPane.YES_OPTION)
         		    { 
         		       clip.stop();
                        flag2 = false;
                        count = 0;
                        count1=0;
                      }
                     if(i==JOptionPane.NO_OPTION)
                     {
                     	clip.stop();
                     	count1=0;
                     }
                     
                     
                 }
                    
                
    				
    	  }
	    }

		catch(NumberFormatException e2)//异常处理
		{
			JOptionPane.showMessageDialog(null,"闹钟设定错误！");
			flag=false;
		}
		
   }
	public void run()//线程部分
			{
			     while(true)
			        {
			        try{
			        	    cal=Calendar.getInstance(); 
				            h=cal.get(Calendar.HOUR_OF_DAY); 
				            mi=cal.get(Calendar.MINUTE); 
				            s=cal.get(Calendar.SECOND);
			        	     Alarm();//调用alarm
			        	     Thread.sleep(1000);
					    }
			        catch (InterruptedException ex)
			            {
			            
							ex.printStackTrace();
						
			            } catch (MalformedURLException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}

			       }
	}
	@Override
	public void play() {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void loop() {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void stop() {
		// TODO Auto-generated method stub
		
	}
}
