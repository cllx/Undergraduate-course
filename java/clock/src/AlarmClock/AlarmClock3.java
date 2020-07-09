package AlarmClock;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Frame;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.IOException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Timer;
import java.util.TimerTask;
 
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.LineEvent;
import javax.sound.sampled.LineListener;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.UnsupportedAudioFileException;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
/**
 * 闹钟主界面
 */
public class AlarmClock3 extends JFrame implements ActionListener {
    private static final int LOOP_COUNT = 5; // 重复播放的次数
    private JLabel labelClock, labelAlarm, labelNextAlarm;
    private JButton btnSet, btnClose;
    private SetDialog setDialog;
    private JPanel topPanel, alarmPanel;
    private Timer timer;
    private Clip clip;
    private Calendar alarmCal;
    private boolean timeReached = true;
    private DateFormat df = new SimpleDateFormat("HH : mm");
     
    public AlarmClock3() {
        super("闹钟");
    }
     
    public void launch() {
        setSize(400, 300);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
         
        getContentPane().setLayout(new BorderLayout()); // 利用边界布局将界面分割成上中下三部分
        labelAlarm = new JLabel("闹钟定时已到！");
        btnClose = new JButton("确定");
        labelNextAlarm = new JLabel(); // 指示下一次闹钟时间
        alarmPanel = new JPanel(new FlowLayout(FlowLayout.CENTER)); // 顶部提示栏提示闹钟时间已到，和确定按钮
        alarmPanel.add(labelAlarm);
        alarmPanel.add(btnClose);
         
        topPanel = new JPanel(new GridLayout(2, 1));
        topPanel.add(alarmPanel);
        topPanel.add(labelNextAlarm);
        alarmPanel.setVisible(false); // 初始隐藏顶部提示栏
         
        labelClock = new JLabel();
        Font font = new Font(Font.SERIF, Font.PLAIN, 48); // 中间的倒计时文本用大号字体展示
        labelClock.setFont(font);
        labelClock.setHorizontalAlignment(JLabel.CENTER); // 文本居中
        btnSet = new JButton("设置");
         
        getContentPane().add(topPanel, BorderLayout.NORTH); // 界面顶部
        getContentPane().add(labelClock, BorderLayout.CENTER); // 界面中部
        getContentPane().add(btnSet, BorderLayout.SOUTH); // 界面底部
         
        btnSet.addActionListener(this); // 设置按钮的点击事件
        btnClose.addActionListener(this); // 顶部确定按钮的点击事件
        setLocationRelativeTo(null); // 界面居中
        setDialog = new SetDialog(this); // 初始化设置对话框
 
        try { // 初始化闹钟声音
            // 目前发现wav格式的文件是可以支持的，mp3不支持
            AudioInputStream ais = AudioSystem.getAudioInputStream(
                    AlarmClock.class.getResource("/res/alarm.wav"));
            clip = AudioSystem.getClip();
            clip.open(ais);
            ais.close();
            int loop = LOOP_COUNT <= 0 ? 1 : LOOP_COUNT;
            final long totalFrames = ais.getFrameLength() * loop;
            clip.addLineListener(new LineListener() {
                @Override
                public void update(LineEvent e) {
                    // 当闹钟音乐播放结束时，自动隐藏顶部提示栏
                    if(e.getFramePosition() >= totalFrames) {
                        stopAlarm();
                    }
                }
            });
        } catch (UnsupportedAudioFileException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (LineUnavailableException e) {
            e.printStackTrace();
        }
        initTimer();
    }
 
    public static void main(String[] args) {
        new AlarmClock3().launch(); // 启动主界面
    }
 
    @Override
    public void actionPerformed(ActionEvent e) {
        Object source = e.getSource();
        if(source == btnSet) { // 点击设置按钮时弹出设置界面，以模对话框显示
            setDialog.setVisible(true);
        } else if(source == btnClose) { // 点击顶部确定按钮时隐藏顶部提示栏
            stopAlarm();
        }
    }
     
    private void initTimer() {
        timer = new Timer(); // 初始化倒计时任务
        // 开始倒计时
        timer.scheduleAtFixedRate(new TimerTask() {
            @Override
            public void run() {
                Calendar cal = Calendar.getInstance();
                int hour = cal.get(Calendar.HOUR_OF_DAY);
                int min = cal.get(Calendar.MINUTE);
                int sec = cal.get(Calendar.SECOND);
                // 设置倒计时文本
                labelClock.setText(String.format("%02d : %02d : %02d", hour, min, sec));
                if(null != alarmCal && !timeReached) {
                    int alarmHour = alarmCal.get(Calendar.HOUR_OF_DAY);
                    int alarmMin = alarmCal.get(Calendar.MINUTE);
                    if(alarmHour == hour && alarmMin == min) { // 到时间时播放声音
                        timeReached = true;
                        System.out.println("Time over");
                        startAlarm();
                    }
                }
            }
        }, 0, 1000L); // 每隔1秒刷新倒计时文本
    }
     
    /**
     * 开始计时
     * @param hour
     * @param minute
     */
    public void startTimer(int hour, int minute) {
        alarmCal = Calendar.getInstance();
        alarmCal.set(Calendar.HOUR_OF_DAY, hour);
        alarmCal.set(Calendar.MINUTE, minute);
        labelNextAlarm.setText("下次闹钟时间：" + df.format(alarmCal.getTime()));
        timeReached = false;
    }
     
    /**
     * 取消倒计时任务
     */
    public void cancelTimer() {
        labelNextAlarm.setText("");
        alarmCal = null;
    }
     
    private void startAlarm() { // 开始播放提示音
        if(null != clip) {
            alarmPanel.setVisible(true); // 显示顶部提示栏
            clip.setFramePosition(0); // 将音频帧重置为第0帧
            clip.loop(LOOP_COUNT); // 开始循环播放
        }
        labelNextAlarm.setText("");
    }
    private void stopAlarm() { // 停止播放提示音
        if(null != clip && clip.isRunning()) {
            clip.stop(); // 结束播放
        }
        labelNextAlarm.setText("");
        alarmPanel.setVisible(false); // 隐藏顶部提示栏
    }
     
    /**
     * 闹钟设置页面
     */
    class SetDialog extends JDialog implements KeyListener, ActionListener {
        private JLabel labelHour, labelMin;
        private JTextField textHour, textMin;
        private JPanel mainPanel, labelPanel, buttonPanel;
        private JButton btnOk, btnCancel, btnBack;
        private Calendar cal = Calendar.getInstance();
         
        public SetDialog(Frame frame) {
            super(frame);
            setTitle("设置");
            setModal(true); // 设置为模窗口，就是说在本弹窗未消失时不允许点击主界面。
            setSize(300, 150);
            // 显示时分
            labelHour = new JLabel("时");
            labelMin = new JLabel("分");
            labelHour.setHorizontalAlignment(JLabel.CENTER);
            labelMin.setHorizontalAlignment(JLabel.CENTER);
            textHour = new JTextField();
            textMin = new JTextField();
            // 上面的部分用网格布局将各组件以2x2的格子放进去
            labelPanel = new JPanel(new GridLayout(2, 2));
            labelPanel.add(labelHour);
            labelPanel.add(labelMin);
            labelPanel.add(textHour);
            labelPanel.add(textMin);
            // 时分输入框添加按键监听，只允许输入数字
            textHour.addKeyListener(this);
            textMin.addKeyListener(this);
             
            // 初始化按钮
            btnOk = new JButton("确定");
            btnCancel = new JButton("取消");
            btnBack = new JButton("返回");
            // 下面的按钮依次居中放进去
            buttonPanel = new JPanel(new FlowLayout(FlowLayout.CENTER));
            buttonPanel.add(btnBack);
            buttonPanel.add(btnCancel);
            buttonPanel.add(btnOk);
            // 初始化主面板，将主面板分割为上下两部分
            mainPanel = new JPanel(new BorderLayout());
            mainPanel.add(labelPanel, BorderLayout.CENTER); // 上面显示时分的组件
            mainPanel.add(buttonPanel, BorderLayout.SOUTH); // 下面排列三个按钮
            setContentPane(mainPanel);
            // 设置按钮监听
            btnBack.addActionListener(this);
            btnOk.addActionListener(this);
            btnCancel.addActionListener(this);
 
            cal.add(Calendar.HOUR, 1); // 默认设置为当前时间加1小时的整点时间
            cal.set(Calendar.MINUTE, 0);
            int hour = cal.get(Calendar.HOUR_OF_DAY);
            int min = cal.get(Calendar.MINUTE);
            textHour.setText(String.format("%02d", hour));
            textMin.setText(String.format("%02d", min));
            setLocationRelativeTo(frame);
        }
 
        @Override
        public void keyPressed(KeyEvent arg0) {
        }
        @Override
        public void keyReleased(KeyEvent arg0) {
        }
        @Override
        public void keyTyped(KeyEvent e) {
            int keyChar = e.getKeyChar();                 
            if(keyChar >= KeyEvent.VK_0 && keyChar <= KeyEvent.VK_9){
            }else{ // 如果输入的不是数字则屏蔽输入
                e.consume(); //关键，屏蔽掉非法输入  
            } 
        }
 
        @Override
        public void actionPerformed(ActionEvent e) {
            Object source = e.getSource();
            if(source == btnOk) { // 如果点击了确定按钮，则开始计时
                int hour = 0, min = 0;
                try {
                    hour = Integer.parseInt(textHour.getText());
                } catch (NumberFormatException e1) {
                }
                try {
                    min = Integer.parseInt(textMin.getText());
                } catch (NumberFormatException e1) {
                }
                startTimer(hour, min);
                setVisible(false);
            } else if(source == btnCancel) { // 点击取消按钮时取消计时
                cancelTimer();
                setVisible(false);
            } else if(source == btnBack) { // 点击返回按钮时什么也不做，直接关闭设置界面
                setVisible(false);
            }
        }
    }
}