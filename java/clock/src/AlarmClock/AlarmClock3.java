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
 * ����������
 */
public class AlarmClock3 extends JFrame implements ActionListener {
    private static final int LOOP_COUNT = 5; // �ظ����ŵĴ���
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
        super("����");
    }
     
    public void launch() {
        setSize(400, 300);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
         
        getContentPane().setLayout(new BorderLayout()); // ���ñ߽粼�ֽ�����ָ��������������
        labelAlarm = new JLabel("���Ӷ�ʱ�ѵ���");
        btnClose = new JButton("ȷ��");
        labelNextAlarm = new JLabel(); // ָʾ��һ������ʱ��
        alarmPanel = new JPanel(new FlowLayout(FlowLayout.CENTER)); // ������ʾ����ʾ����ʱ���ѵ�����ȷ����ť
        alarmPanel.add(labelAlarm);
        alarmPanel.add(btnClose);
         
        topPanel = new JPanel(new GridLayout(2, 1));
        topPanel.add(alarmPanel);
        topPanel.add(labelNextAlarm);
        alarmPanel.setVisible(false); // ��ʼ���ض�����ʾ��
         
        labelClock = new JLabel();
        Font font = new Font(Font.SERIF, Font.PLAIN, 48); // �м�ĵ���ʱ�ı��ô������չʾ
        labelClock.setFont(font);
        labelClock.setHorizontalAlignment(JLabel.CENTER); // �ı�����
        btnSet = new JButton("����");
         
        getContentPane().add(topPanel, BorderLayout.NORTH); // ���涥��
        getContentPane().add(labelClock, BorderLayout.CENTER); // �����в�
        getContentPane().add(btnSet, BorderLayout.SOUTH); // ����ײ�
         
        btnSet.addActionListener(this); // ���ð�ť�ĵ���¼�
        btnClose.addActionListener(this); // ����ȷ����ť�ĵ���¼�
        setLocationRelativeTo(null); // �������
        setDialog = new SetDialog(this); // ��ʼ�����öԻ���
 
        try { // ��ʼ����������
            // Ŀǰ����wav��ʽ���ļ��ǿ���֧�ֵģ�mp3��֧��
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
                    // ���������ֲ��Ž���ʱ���Զ����ض�����ʾ��
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
        new AlarmClock3().launch(); // ����������
    }
 
    @Override
    public void actionPerformed(ActionEvent e) {
        Object source = e.getSource();
        if(source == btnSet) { // ������ð�ťʱ�������ý��棬��ģ�Ի�����ʾ
            setDialog.setVisible(true);
        } else if(source == btnClose) { // �������ȷ����ťʱ���ض�����ʾ��
            stopAlarm();
        }
    }
     
    private void initTimer() {
        timer = new Timer(); // ��ʼ������ʱ����
        // ��ʼ����ʱ
        timer.scheduleAtFixedRate(new TimerTask() {
            @Override
            public void run() {
                Calendar cal = Calendar.getInstance();
                int hour = cal.get(Calendar.HOUR_OF_DAY);
                int min = cal.get(Calendar.MINUTE);
                int sec = cal.get(Calendar.SECOND);
                // ���õ���ʱ�ı�
                labelClock.setText(String.format("%02d : %02d : %02d", hour, min, sec));
                if(null != alarmCal && !timeReached) {
                    int alarmHour = alarmCal.get(Calendar.HOUR_OF_DAY);
                    int alarmMin = alarmCal.get(Calendar.MINUTE);
                    if(alarmHour == hour && alarmMin == min) { // ��ʱ��ʱ��������
                        timeReached = true;
                        System.out.println("Time over");
                        startAlarm();
                    }
                }
            }
        }, 0, 1000L); // ÿ��1��ˢ�µ���ʱ�ı�
    }
     
    /**
     * ��ʼ��ʱ
     * @param hour
     * @param minute
     */
    public void startTimer(int hour, int minute) {
        alarmCal = Calendar.getInstance();
        alarmCal.set(Calendar.HOUR_OF_DAY, hour);
        alarmCal.set(Calendar.MINUTE, minute);
        labelNextAlarm.setText("�´�����ʱ�䣺" + df.format(alarmCal.getTime()));
        timeReached = false;
    }
     
    /**
     * ȡ������ʱ����
     */
    public void cancelTimer() {
        labelNextAlarm.setText("");
        alarmCal = null;
    }
     
    private void startAlarm() { // ��ʼ������ʾ��
        if(null != clip) {
            alarmPanel.setVisible(true); // ��ʾ������ʾ��
            clip.setFramePosition(0); // ����Ƶ֡����Ϊ��0֡
            clip.loop(LOOP_COUNT); // ��ʼѭ������
        }
        labelNextAlarm.setText("");
    }
    private void stopAlarm() { // ֹͣ������ʾ��
        if(null != clip && clip.isRunning()) {
            clip.stop(); // ��������
        }
        labelNextAlarm.setText("");
        alarmPanel.setVisible(false); // ���ض�����ʾ��
    }
     
    /**
     * ��������ҳ��
     */
    class SetDialog extends JDialog implements KeyListener, ActionListener {
        private JLabel labelHour, labelMin;
        private JTextField textHour, textMin;
        private JPanel mainPanel, labelPanel, buttonPanel;
        private JButton btnOk, btnCancel, btnBack;
        private Calendar cal = Calendar.getInstance();
         
        public SetDialog(Frame frame) {
            super(frame);
            setTitle("����");
            setModal(true); // ����Ϊģ���ڣ�����˵�ڱ�����δ��ʧʱ�������������档
            setSize(300, 150);
            // ��ʾʱ��
            labelHour = new JLabel("ʱ");
            labelMin = new JLabel("��");
            labelHour.setHorizontalAlignment(JLabel.CENTER);
            labelMin.setHorizontalAlignment(JLabel.CENTER);
            textHour = new JTextField();
            textMin = new JTextField();
            // ����Ĳ��������񲼾ֽ��������2x2�ĸ��ӷŽ�ȥ
            labelPanel = new JPanel(new GridLayout(2, 2));
            labelPanel.add(labelHour);
            labelPanel.add(labelMin);
            labelPanel.add(textHour);
            labelPanel.add(textMin);
            // ʱ���������Ӱ���������ֻ������������
            textHour.addKeyListener(this);
            textMin.addKeyListener(this);
             
            // ��ʼ����ť
            btnOk = new JButton("ȷ��");
            btnCancel = new JButton("ȡ��");
            btnBack = new JButton("����");
            // ����İ�ť���ξ��зŽ�ȥ
            buttonPanel = new JPanel(new FlowLayout(FlowLayout.CENTER));
            buttonPanel.add(btnBack);
            buttonPanel.add(btnCancel);
            buttonPanel.add(btnOk);
            // ��ʼ������壬�������ָ�Ϊ����������
            mainPanel = new JPanel(new BorderLayout());
            mainPanel.add(labelPanel, BorderLayout.CENTER); // ������ʾʱ�ֵ����
            mainPanel.add(buttonPanel, BorderLayout.SOUTH); // ��������������ť
            setContentPane(mainPanel);
            // ���ð�ť����
            btnBack.addActionListener(this);
            btnOk.addActionListener(this);
            btnCancel.addActionListener(this);
 
            cal.add(Calendar.HOUR, 1); // Ĭ������Ϊ��ǰʱ���1Сʱ������ʱ��
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
            }else{ // �������Ĳ�����������������
                e.consume(); //�ؼ������ε��Ƿ�����  
            } 
        }
 
        @Override
        public void actionPerformed(ActionEvent e) {
            Object source = e.getSource();
            if(source == btnOk) { // ��������ȷ����ť����ʼ��ʱ
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
            } else if(source == btnCancel) { // ���ȡ����ťʱȡ����ʱ
                cancelTimer();
                setVisible(false);
            } else if(source == btnBack) { // ������ذ�ťʱʲôҲ������ֱ�ӹر����ý���
                setVisible(false);
            }
        }
    }
}