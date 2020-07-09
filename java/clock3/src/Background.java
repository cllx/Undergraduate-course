import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JPanel;


public class Background extends JPanel{
	public void paintComponent(Graphics g)
	{
	    super.paintComponent(g);
		try{
	        BufferedImage img = ImageIO.read(this.getClass().getResource("Background.png"));
	        g.drawImage(img, 0, 0, this.getWidth(), this.getHeight(), null);
	      } catch (IOException e) 
               {
                  e.printStackTrace();
                }
}}
