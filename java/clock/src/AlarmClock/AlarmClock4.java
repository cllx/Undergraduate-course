package AlarmClock;
import java.util.*;
import java.awt.*;
import java.applet.*;
import java.text.*;

public class AlarmClock4 extends Applet implements Runnable
{
    Thread timer=null; //创建线程timer
    Image clockp,gif1,gif2,clock6,clock7; //clockp:闹钟的外壳，闹铃和报时鸟
    int s,m,h,hh;
    AudioClip ipAu,danger,chirp;
    boolean canPaint=true;
    boolean flag=false;
    boolean strike=true;
    int counter=0;
    int lasts;
    Image offscreen_buf=null;
    int i,j,t=0;
    int timeout=166;
    int lastxs=0,lastys=0,lastxm=0,lastym=0,lastxh=0,lastyh=0;
    Date dummy=new Date();  //生成Data对象
    GregorianCalendar cal=new GregorianCalendar();
    SimpleDateFormat df=new SimpleDateFormat("yyyy MM dd HH:mm:ss");//设置时间格式
    String lastdate=df.format(dummy);
    Font F=new Font("TimesRoman",Font.PLAIN,14);//设置字体格式
    Date dat=null;
    Date timeNow=null;
    Color fgcol=Color.blue;
    Color fgcol2=Color.darkGray;
    
    Panel setpanel;
    Color backcolor=Color.pink;
    TextField showhour,showmin,showsec,sethour,setmin,setsec;//显示当前时间文本框和定时文本框
    Button onbutton;
    Button offbutton;
    Label hlabel1,mlabel1,slabel1,hlabel2,mlabel2,slabel2;//显示时间单位时所用的标签（时、分、秒）
    Label info1=new Label("欢迎使用定时提醒闹钟"),info2=new Label("");
    Label note1=new Label("当前时间:"),note2=new Label("闹钟设置:");
    boolean setalerm=false,clickflag=false;//判断是否响铃和振动
    int fixh=0,fixm=0,fixs=0;//记录闹钟的定时
    
    public void init()//初始化方法
    {
       Integer gif_number;
       int fieldx=50,fieldy1=120,fieldy2=220,fieldw=30,fieldh=20,space=50;//显示时间和定时文本框的定位参数
       
       setLayout(null);          //将布局管理器初始化为null
       setpanel=new Panel();
       setpanel.setLayout(null);
       setpanel.add(note1);
       setpanel.add(note2);
       note1.setBounds(30,100,60,20);
       note1.setBackground(backcolor);
       note1.setForeground(Color.black);
       note2.setBounds(30,180,60,20);
       note2.setBackground(backcolor);
       note2.setForeground(Color.black);
       
       hlabel1=new Label();
       mlabel1=new Label(); 
       slabel1=new Label();
       hlabel2=new Label();
       mlabel2=new Label();
       slabel2=new Label();
       //显示当前时间用的文本框
       showhour=new TextField("00",5);
       showmin=new TextField("00",5);
       showsec=new TextField("00",5);
       //定时用的文本框（时、分、秒）
       sethour=new TextField("00",5);
       setmin=new TextField("00",5);
       setsec=new TextField("00",5);
       //当前时间用的文本框的位置、大小
       setpanel.add(showhour);
       showhour.setBounds(fieldx,fieldy1,fieldw,fieldh);
       showhour.setBackground(Color.white);
       //在文本框后加入单位“时”
       setpanel.add(hlabel1);
       hlabel1.setText("时");
       hlabel1.setBackground(backcolor);
       hlabel1.setForeground(Color.black);
       hlabel1.setBounds(fieldx+fieldw+3,fieldy1,14,20);
       fieldx=fieldx+space;
       //当前时间的分钟文本框的位置、大小
       setpanel.add(showmin);
       showmin.setBounds(fieldx,fieldy1,fieldw,fieldh);
       showmin.setBackground(Color.white);
       //在文本框后加入单位“分”
       setpanel.add(mlabel1);
       mlabel1.setText("分");
       mlabel1.setBackground(backcolor);
       mlabel1.setForeground(Color.black);
       mlabel1.setBounds(fieldx+fieldw+3,fieldy1,14,20);
       fieldx=fieldx+space;
       //当前时间的秒文本框的位置、大小
       setpanel.add(showsec);
       showsec.setBounds(fieldx,fieldy1,fieldw,fieldh);
       showsec.setBackground(Color.white);
       //在文本框后加入单位“秒”
       setpanel.add(slabel1);
       slabel1.setText("秒");
       slabel1.setBackground(backcolor);
       slabel1.setForeground(Color.black);
       slabel1.setBounds(fieldx+fieldw+3,fieldy1,14,20);
       fieldx=50;
       //定时的小时文本框的位置、大小
       setpanel.add(sethour);
       sethour.setBounds(fieldx,fieldy2,fieldw,fieldh);
       sethour.setBackground(Color.white);
       //在文本框后加入单位“时”
       setpanel.add(hlabel2);
       hlabel2.setText("时");
       hlabel2.setBackground(backcolor);
       hlabel2.setForeground(Color.black);
       hlabel2.setBounds(fieldx+fieldw+3,fieldy2,14,20);
       fieldx=fieldx+space;
       //定时的分钟文本框的位置、大小
       setpanel.add(setmin);
       setmin.setBounds(fieldx,fieldy2,fieldw,fieldh);
       setmin.setBackground(Color.white);
       //在文本框后加入单位“分”
       setpanel.add(mlabel2);
       mlabel2.setText("分");
       mlabel2.setBackground(backcolor);
       mlabel2.setForeground(Color.black);
       mlabel2.setBounds(fieldx+fieldw+3,fieldy2,14,20);
       fieldx=fieldx+space;
       //定时的秒文本框的位置、大小
       setpanel.add(setsec);
       setsec.setBounds(fieldx,fieldy2,fieldw,fieldh);
       setsec.setBackground(Color.white);
       //在文本框后加入单位“秒”
       setpanel.add(slabel2);
       slabel2.setText("秒");
       slabel2.setBackground(backcolor);
       slabel2.setForeground(Color.black);
       slabel2.setBounds(fieldx+fieldw+3,fieldy2,14,20);
       //设置闹钟控制按钮（on,off)
       onbutton=new Button("开");
       offbutton=new Button("关");
       setpanel.add(onbutton);
       setpanel.add(offbutton);
       onbutton.setBounds(90,180,40,20);
       offbutton.setBounds(140,180,40,20);
       //加入一些附加的信息标签（题头，题尾）
       setpanel.add(info1);
       info1.setBackground(backcolor);
       info1.setForeground(Color.blue);
       info1.setBounds(50,50,150,20);
       setpanel.add(info2);
       info2.setBackground(backcolor);

       info2.setForeground(Color.blue);
       info2.setBounds(150,280,100,20);
       //将面板加入当前容器中，并设置面板的大小和背景色
       add(setpanel);
       setpanel.setBounds(300,1,250,420);
       setpanel.setBackground(backcolor);
       //获取声音文件
       ipAu=getAudioClip(getDocumentBase(),"bells/仙剑.mid");
       danger=getAudioClip(getDocumentBase(),"bells/0.mid");
       chirp=getAudioClip(getDocumentBase(),"bells/3.mid");
       
       int xcenter,ycenter,s,m,h;
       xcenter=145;
       ycenter=162;
       s=(int)cal.get(Calendar.SECOND);
       m=(int)cal.get(Calendar.MINUTE);
       h=(int)cal.get(Calendar.HOUR_OF_DAY);
       //初始化指针位置
       lastxs=(int)(Math.cos(s*3.14f/30-3.14f/2)*30+xcenter);
       lastys=(int)(Math.sin(s*3.14f/30-3.14f/2)*30+ycenter);
       lastxm=(int)(Math.cos(m*3.14f/30-3.14f/2)*25+xcenter);
       lastym=(int)(Math.sin(m*3.14f/30-3.14f/2)*25+ycenter);
       lastxh=(int)(Math.cos((h*30+m/2)*3.14f/180-3.14f/2)*18+xcenter);
       lastyh=(int)(Math.sin((h*30+m/2)*3.14f/180-3.14f/2)*18+ycenter);
       lasts=s;
       
       MediaTracker mt=new MediaTracker(this);//创建Tracke对象
       clockp=getImage(getDocumentBase(),"休闲.png");
       gif1=getImage(getDocumentBase(),"gif1.gif");
       gif2=getImage(getDocumentBase(),"gif2.gif");
       clock6=getImage(getDocumentBase(),"clock6.gif");
       clock7=getImage(getDocumentBase(),"clock7.gif");
       mt.addImage(clockp,i++);
       mt.addImage(gif1,i++);
       mt.addImage(gif2,i++);
       mt.addImage(clock6,i++);
       mt.addImage(clock7,i++);
       try{mt.waitForAll();}catch(InterruptedException e){};//等待加载结束
       resize(600,420);//设置窗口大小
    }
    
    public void paint(Graphics g){//重写paint()方法
    int xh,yh,xm,ym,xs,ys,strike_times;
    int xcenter,ycenter;
    String today;
    Integer gif_number;
    xcenter=148;
    ycenter=186;
    dat=new Date();
    cal.setTime(dat);
    //读取当前时间
    s=(int)cal.get(Calendar.SECOND);
    m=(int)cal.get(Calendar.MINUTE);
    h=(int)cal.get(Calendar.HOUR_OF_DAY);
    today=df.format(dat);
    //指针位置
    xs=(int)(Math.cos(s*3.14f/30-3.14f/2)*30+xcenter);
    ys=(int)(Math.sin(s*3.14f/30-3.14f/2)*30+ycenter);
    xm=(int)(Math.cos(m*3.14f/30-3.14f/2)*25+xcenter);
    ym=(int)(Math.sin(m*3.14f/30-3.14f/2)*25+ycenter);
    xh=(int)(Math.cos((h*30+m/2)*3.14f/180-3.14f/2)*18+xcenter);
    yh=(int)(Math.sin((h*30+m/2)*3.14f/180-3.14f/2)*18+ycenter);
    //设置字体和颜色
    g.setFont(F);
    g.setColor(fgcol);
    g.setColor(fgcol2);
    g.setColor(getBackground());
    g.fillRect(1,1,634,419);
    g.drawImage(clockp,75,110,this);
    g.drawImage(clock6,83,280,this);
    g.setColor(fgcol2);
    g.setColor(getBackground());
    g.setColor(fgcol2);
    //以数字方式显示年、月、日和时间
    g.drawString(today,55,415);
    g.drawLine(xcenter,ycenter,xs,ys);
    g.setColor(fgcol);
    //画指针
    g.drawLine(xcenter,ycenter-1,xm,ym);
    g.drawLine(xcenter-1,ycenter,xm,ym);
    g.drawLine(xcenter,ycenter-1,xh,yh);
    g.drawLine(xcenter-1,ycenter,xh,yh);
    lastxs=xs;lastys=ys;
    lastxm=xh;lastym=ym;
    lastxh=xh;lastyh=yh;
    lastdate=today;
    
    if(h<12)hh=h;//将系统时间变换到0-11区间
    else hh=h-12;
    if(hh==0) strike_times=12;//计算整点时钟声数
    else strike_times=hh;
    if((s==0&&m==0)||flag){//判断是否整点，是否是主动刷新
        if(counter<strike_times){
            flag=true;
            g.drawImage(gif2,115,35,this);
            if(lasts!=s){
                if(strike){
                    counter++;
                    danger.play();//播放闹铃声
                }
                if(strike)strike=false;
                else strike=true;
            }
        }
        else {
            counter=0;
            flag=false;
        }
    }
    else
        g.drawImage(gif1,115,35,this);
    
    int timedelta;//记录当前时间与闹铃定时的时差
    Integer currh,currm,currs;//分别记录当前的时、分、秒
    
    timeNow=new Date();
    currh=new Integer(timeNow.getHours());
    currm=new Integer(timeNow.getMinutes());
    currs=new Integer(timeNow.getSeconds());
    //判断是否要更新当前显示的时间，这样可以避免文本框出现频率闪动
    if(currh.intValue()!=Integer.valueOf(showhour.getText()).intValue())
        showhour.setText(currh.toString());
    if(currm.intValue()!=Integer.valueOf(showmin.getText()).intValue())
        showmin.setText(currh.toString());
    if(currs.intValue()!=Integer.valueOf(showsec.getText()).intValue())
        showsec.setText(currh.toString());
    
    if(setalerm){  //判断是否设置了闹钟
        //判断当前时间是否为闹钟所定的时间
        if((currh.intValue()==fixh)&&(currm.intValue()==fixm)&&(currs.intValue()==fixs))
            clickflag=true;
        timedelta=currm.intValue()*60+currs.intValue()-fixm*60-fixs;
        if((timedelta<60)&&(clickflag==true)){  //若当前时间与闹钟相差时间达到60秒
            chirp.play();
            g.drawImage(clock7,83,280,this);
        }
        else{
            chirp.stop();
            clickflag=false;
        }
    }
    if(lasts!=s)
        ipAu.play();//播放滴答声
    lasts=s;
    if(canPaint){
        t+=1;
        if(t==12)t=0;
    }
    canPaint=false;
    dat=null;
}
public void start(){
    if(timer==null){
        timer=new Thread(this);//将timer实例化
        timer.start();
    }
}
public void stop(){
    timer=null;
}
public void run(){
    while(timer!=null){
        try{timer.sleep(timeout);}catch(InterruptedException e){}
        canPaint=true;
        repaint();//刷新画面
    }
        timer=null;
    }
    
    public void update(Graphics g){ //采用双缓冲技术的update()方法
        if(offscreen_buf==null)
            offscreen_buf=createImage(600,420);
        Graphics offg=offscreen_buf.getGraphics();
        offg.clipRect(1,1,599,419);
        paint(offg);
        Graphics ong=getGraphics();
        ong.clipRect(1,1,599,419);
        ong.drawImage(offscreen_buf,0,0,this);
    }
    
    public boolean action(Event evt,Object arg){  //按钮事件处理函数
        if(evt.target instanceof Button){
            String lable=(String)arg;
            if(lable.equals("开")){
                setalerm=true;
                //获取输入的时间
                fixh=Integer.valueOf(sethour.getText()).intValue();
                fixm=Integer.valueOf(setmin.getText()).intValue();
                fixs=Integer.valueOf(setsec.getText()).intValue();
                
                clickflag=false;
            }
            if(lable.equals("关")){
                setalerm=false;
                if(chirp!=null)
                    chirp.stop();
                clickflag=false;
            }
            return true;
        }
        return false;
    }
}