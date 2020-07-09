import java.awt.*;

import javax.swing.*;

import java.net.MalformedURLException;
import java.util.concurrent.*;
public class Window extends JFrame {
	public Window() throws MalformedURLException
	{
		super("闹钟");
		JTabbedPane Pane=new JTabbedPane();//标签
		Clock clock=new Clock();
		Time time=new Time(clock);
		clock.q.setOpaque(false);//设置背景透明
		clock.q.setBounds(0,0,410,30);
		time.back.add(clock.q);
		ExecutorService threadExecutor =Executors.newFixedThreadPool(2);//线程池
		threadExecutor.execute(clock);//线程开启
		threadExecutor.execute(time);
		Pane.addTab("现在时间",null,clock);//标签设定
		Pane.addTab("闹钟设定",null,time);
		threadExecutor.shutdown();
		add(Pane);
		setBounds(100, 100, 410, 435);//此语句为窗口在显示屏的位置及其大小
		setResizable(false);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	
		
	}
	public static void main(String[] args) throws MalformedURLException {
		new Window();
	}
}
