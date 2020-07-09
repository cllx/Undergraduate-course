package AlarmClock;
import java.util.*;
import java.awt.*;
import java.applet.*;
import java.text.*;

public class AlarmClock4 extends Applet implements Runnable
{
    Thread timer=null; //�����߳�timer
    Image clockp,gif1,gif2,clock6,clock7; //clockp:���ӵ���ǣ�����ͱ�ʱ��
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
    Date dummy=new Date();  //����Data����
    GregorianCalendar cal=new GregorianCalendar();
    SimpleDateFormat df=new SimpleDateFormat("yyyy MM dd HH:mm:ss");//����ʱ���ʽ
    String lastdate=df.format(dummy);
    Font F=new Font("TimesRoman",Font.PLAIN,14);//���������ʽ
    Date dat=null;
    Date timeNow=null;
    Color fgcol=Color.blue;
    Color fgcol2=Color.darkGray;
    
    Panel setpanel;
    Color backcolor=Color.pink;
    TextField showhour,showmin,showsec,sethour,setmin,setsec;//��ʾ��ǰʱ���ı���Ͷ�ʱ�ı���
    Button onbutton;
    Button offbutton;
    Label hlabel1,mlabel1,slabel1,hlabel2,mlabel2,slabel2;//��ʾʱ�䵥λʱ���õı�ǩ��ʱ���֡��룩
    Label info1=new Label("��ӭʹ�ö�ʱ��������"),info2=new Label("");
    Label note1=new Label("��ǰʱ��:"),note2=new Label("��������:");
    boolean setalerm=false,clickflag=false;//�ж��Ƿ��������
    int fixh=0,fixm=0,fixs=0;//��¼���ӵĶ�ʱ
    
    public void init()//��ʼ������
    {
       Integer gif_number;
       int fieldx=50,fieldy1=120,fieldy2=220,fieldw=30,fieldh=20,space=50;//��ʾʱ��Ͷ�ʱ�ı���Ķ�λ����
       
       setLayout(null);          //�����ֹ�������ʼ��Ϊnull
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
       //��ʾ��ǰʱ���õ��ı���
       showhour=new TextField("00",5);
       showmin=new TextField("00",5);
       showsec=new TextField("00",5);
       //��ʱ�õ��ı���ʱ���֡��룩
       sethour=new TextField("00",5);
       setmin=new TextField("00",5);
       setsec=new TextField("00",5);
       //��ǰʱ���õ��ı����λ�á���С
       setpanel.add(showhour);
       showhour.setBounds(fieldx,fieldy1,fieldw,fieldh);
       showhour.setBackground(Color.white);
       //���ı������뵥λ��ʱ��
       setpanel.add(hlabel1);
       hlabel1.setText("ʱ");
       hlabel1.setBackground(backcolor);
       hlabel1.setForeground(Color.black);
       hlabel1.setBounds(fieldx+fieldw+3,fieldy1,14,20);
       fieldx=fieldx+space;
       //��ǰʱ��ķ����ı����λ�á���С
       setpanel.add(showmin);
       showmin.setBounds(fieldx,fieldy1,fieldw,fieldh);
       showmin.setBackground(Color.white);
       //���ı������뵥λ���֡�
       setpanel.add(mlabel1);
       mlabel1.setText("��");
       mlabel1.setBackground(backcolor);
       mlabel1.setForeground(Color.black);
       mlabel1.setBounds(fieldx+fieldw+3,fieldy1,14,20);
       fieldx=fieldx+space;
       //��ǰʱ������ı����λ�á���С
       setpanel.add(showsec);
       showsec.setBounds(fieldx,fieldy1,fieldw,fieldh);
       showsec.setBackground(Color.white);
       //���ı������뵥λ���롱
       setpanel.add(slabel1);
       slabel1.setText("��");
       slabel1.setBackground(backcolor);
       slabel1.setForeground(Color.black);
       slabel1.setBounds(fieldx+fieldw+3,fieldy1,14,20);
       fieldx=50;
       //��ʱ��Сʱ�ı����λ�á���С
       setpanel.add(sethour);
       sethour.setBounds(fieldx,fieldy2,fieldw,fieldh);
       sethour.setBackground(Color.white);
       //���ı������뵥λ��ʱ��
       setpanel.add(hlabel2);
       hlabel2.setText("ʱ");
       hlabel2.setBackground(backcolor);
       hlabel2.setForeground(Color.black);
       hlabel2.setBounds(fieldx+fieldw+3,fieldy2,14,20);
       fieldx=fieldx+space;
       //��ʱ�ķ����ı����λ�á���С
       setpanel.add(setmin);
       setmin.setBounds(fieldx,fieldy2,fieldw,fieldh);
       setmin.setBackground(Color.white);
       //���ı������뵥λ���֡�
       setpanel.add(mlabel2);
       mlabel2.setText("��");
       mlabel2.setBackground(backcolor);
       mlabel2.setForeground(Color.black);
       mlabel2.setBounds(fieldx+fieldw+3,fieldy2,14,20);
       fieldx=fieldx+space;
       //��ʱ�����ı����λ�á���С
       setpanel.add(setsec);
       setsec.setBounds(fieldx,fieldy2,fieldw,fieldh);
       setsec.setBackground(Color.white);
       //���ı������뵥λ���롱
       setpanel.add(slabel2);
       slabel2.setText("��");
       slabel2.setBackground(backcolor);
       slabel2.setForeground(Color.black);
       slabel2.setBounds(fieldx+fieldw+3,fieldy2,14,20);
       //�������ӿ��ư�ť��on,off)
       onbutton=new Button("��");
       offbutton=new Button("��");
       setpanel.add(onbutton);
       setpanel.add(offbutton);
       onbutton.setBounds(90,180,40,20);
       offbutton.setBounds(140,180,40,20);
       //����һЩ���ӵ���Ϣ��ǩ����ͷ����β��
       setpanel.add(info1);
       info1.setBackground(backcolor);
       info1.setForeground(Color.blue);
       info1.setBounds(50,50,150,20);
       setpanel.add(info2);
       info2.setBackground(backcolor);

       info2.setForeground(Color.blue);
       info2.setBounds(150,280,100,20);
       //�������뵱ǰ�����У����������Ĵ�С�ͱ���ɫ
       add(setpanel);
       setpanel.setBounds(300,1,250,420);
       setpanel.setBackground(backcolor);
       //��ȡ�����ļ�
       ipAu=getAudioClip(getDocumentBase(),"bells/�ɽ�.mid");
       danger=getAudioClip(getDocumentBase(),"bells/0.mid");
       chirp=getAudioClip(getDocumentBase(),"bells/3.mid");
       
       int xcenter,ycenter,s,m,h;
       xcenter=145;
       ycenter=162;
       s=(int)cal.get(Calendar.SECOND);
       m=(int)cal.get(Calendar.MINUTE);
       h=(int)cal.get(Calendar.HOUR_OF_DAY);
       //��ʼ��ָ��λ��
       lastxs=(int)(Math.cos(s*3.14f/30-3.14f/2)*30+xcenter);
       lastys=(int)(Math.sin(s*3.14f/30-3.14f/2)*30+ycenter);
       lastxm=(int)(Math.cos(m*3.14f/30-3.14f/2)*25+xcenter);
       lastym=(int)(Math.sin(m*3.14f/30-3.14f/2)*25+ycenter);
       lastxh=(int)(Math.cos((h*30+m/2)*3.14f/180-3.14f/2)*18+xcenter);
       lastyh=(int)(Math.sin((h*30+m/2)*3.14f/180-3.14f/2)*18+ycenter);
       lasts=s;
       
       MediaTracker mt=new MediaTracker(this);//����Tracke����
       clockp=getImage(getDocumentBase(),"����.png");
       gif1=getImage(getDocumentBase(),"gif1.gif");
       gif2=getImage(getDocumentBase(),"gif2.gif");
       clock6=getImage(getDocumentBase(),"clock6.gif");
       clock7=getImage(getDocumentBase(),"clock7.gif");
       mt.addImage(clockp,i++);
       mt.addImage(gif1,i++);
       mt.addImage(gif2,i++);
       mt.addImage(clock6,i++);
       mt.addImage(clock7,i++);
       try{mt.waitForAll();}catch(InterruptedException e){};//�ȴ����ؽ���
       resize(600,420);//���ô��ڴ�С
    }
    
    public void paint(Graphics g){//��дpaint()����
    int xh,yh,xm,ym,xs,ys,strike_times;
    int xcenter,ycenter;
    String today;
    Integer gif_number;
    xcenter=148;
    ycenter=186;
    dat=new Date();
    cal.setTime(dat);
    //��ȡ��ǰʱ��
    s=(int)cal.get(Calendar.SECOND);
    m=(int)cal.get(Calendar.MINUTE);
    h=(int)cal.get(Calendar.HOUR_OF_DAY);
    today=df.format(dat);
    //ָ��λ��
    xs=(int)(Math.cos(s*3.14f/30-3.14f/2)*30+xcenter);
    ys=(int)(Math.sin(s*3.14f/30-3.14f/2)*30+ycenter);
    xm=(int)(Math.cos(m*3.14f/30-3.14f/2)*25+xcenter);
    ym=(int)(Math.sin(m*3.14f/30-3.14f/2)*25+ycenter);
    xh=(int)(Math.cos((h*30+m/2)*3.14f/180-3.14f/2)*18+xcenter);
    yh=(int)(Math.sin((h*30+m/2)*3.14f/180-3.14f/2)*18+ycenter);
    //�����������ɫ
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
    //�����ַ�ʽ��ʾ�ꡢ�¡��պ�ʱ��
    g.drawString(today,55,415);
    g.drawLine(xcenter,ycenter,xs,ys);
    g.setColor(fgcol);
    //��ָ��
    g.drawLine(xcenter,ycenter-1,xm,ym);
    g.drawLine(xcenter-1,ycenter,xm,ym);
    g.drawLine(xcenter,ycenter-1,xh,yh);
    g.drawLine(xcenter-1,ycenter,xh,yh);
    lastxs=xs;lastys=ys;
    lastxm=xh;lastym=ym;
    lastxh=xh;lastyh=yh;
    lastdate=today;
    
    if(h<12)hh=h;//��ϵͳʱ��任��0-11����
    else hh=h-12;
    if(hh==0) strike_times=12;//��������ʱ������
    else strike_times=hh;
    if((s==0&&m==0)||flag){//�ж��Ƿ����㣬�Ƿ�������ˢ��
        if(counter<strike_times){
            flag=true;
            g.drawImage(gif2,115,35,this);
            if(lasts!=s){
                if(strike){
                    counter++;
                    danger.play();//����������
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
    
    int timedelta;//��¼��ǰʱ�������嶨ʱ��ʱ��
    Integer currh,currm,currs;//�ֱ��¼��ǰ��ʱ���֡���
    
    timeNow=new Date();
    currh=new Integer(timeNow.getHours());
    currm=new Integer(timeNow.getMinutes());
    currs=new Integer(timeNow.getSeconds());
    //�ж��Ƿ�Ҫ���µ�ǰ��ʾ��ʱ�䣬�������Ա����ı������Ƶ������
    if(currh.intValue()!=Integer.valueOf(showhour.getText()).intValue())
        showhour.setText(currh.toString());
    if(currm.intValue()!=Integer.valueOf(showmin.getText()).intValue())
        showmin.setText(currh.toString());
    if(currs.intValue()!=Integer.valueOf(showsec.getText()).intValue())
        showsec.setText(currh.toString());
    
    if(setalerm){  //�ж��Ƿ�����������
        //�жϵ�ǰʱ���Ƿ�Ϊ����������ʱ��
        if((currh.intValue()==fixh)&&(currm.intValue()==fixm)&&(currs.intValue()==fixs))
            clickflag=true;
        timedelta=currm.intValue()*60+currs.intValue()-fixm*60-fixs;
        if((timedelta<60)&&(clickflag==true)){  //����ǰʱ�����������ʱ��ﵽ60��
            chirp.play();
            g.drawImage(clock7,83,280,this);
        }
        else{
            chirp.stop();
            clickflag=false;
        }
    }
    if(lasts!=s)
        ipAu.play();//���ŵδ���
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
        timer=new Thread(this);//��timerʵ����
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
        repaint();//ˢ�»���
    }
        timer=null;
    }
    
    public void update(Graphics g){ //����˫���弼����update()����
        if(offscreen_buf==null)
            offscreen_buf=createImage(600,420);
        Graphics offg=offscreen_buf.getGraphics();
        offg.clipRect(1,1,599,419);
        paint(offg);
        Graphics ong=getGraphics();
        ong.clipRect(1,1,599,419);
        ong.drawImage(offscreen_buf,0,0,this);
    }
    
    public boolean action(Event evt,Object arg){  //��ť�¼�������
        if(evt.target instanceof Button){
            String lable=(String)arg;
            if(lable.equals("��")){
                setalerm=true;
                //��ȡ�����ʱ��
                fixh=Integer.valueOf(sethour.getText()).intValue();
                fixm=Integer.valueOf(setmin.getText()).intValue();
                fixs=Integer.valueOf(setsec.getText()).intValue();
                
                clickflag=false;
            }
            if(lable.equals("��")){
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