package program5;
//Justin Hill
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Calculator extends JFrame implements ActionListener {
    boolean eval = false;
    JPanel[] row = new JPanel[5];
    JButton[] button = new JButton[19];
    String[] buttonString = {"0", "1", "2", "+","3", "4", "5", "-","6", "7", "8", "*", ".", "/", "C", "(",")", "=", "9","+/-"};
    int[] dimW = {300,45,100,90};
    int[] dimH = {35, 40};
    
    //Declare the dimensions
    Dimension displayDimension = new Dimension(dimW[0], dimH[0]);
    
    Dimension regularDimension = new Dimension(dimW[1], dimH[1]);
       
    Dimension rColumnDimension = new Dimension(dimW[2], dimH[1]);
    
    Dimension zeroButDimension = new Dimension(dimW[3], dimH[1]);
    //create temp and bool func
    boolean[] function = new boolean[4];
    double[] temp = {0, 0};
    //create a jtext area
    JTextArea display = new JTextArea(1,20);
    Font font = new Font("Times new Roman", Font.BOLD, 14);

    Calculator() {
        super("Calculator");
        //Set design and size for the window
        setDesign();
        setSize(380, 250);
        setResizable(false);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        GridLayout grid = new GridLayout(5,5);
        setLayout(grid);

        for(int i = 0; i < 4; i++)
            function[i] = false;

        
        FlowLayout f1 = new FlowLayout(FlowLayout.CENTER);
        FlowLayout f2 = new FlowLayout(FlowLayout.CENTER,1,1);
        for(int i = 0; i < 5; i++)
            row[i] = new JPanel();
        row[0].setLayout(f1);
        for(int i = 1; i < 5; i++)
            row[i].setLayout(f2);

        for(int i = 0; i < 19; i++) {
            button[i] = new JButton();
            button[i].setText(buttonString[i]);
            button[i].setFont(font);
            button[i].addActionListener(this);
        }

        display.setFont(font);
        display.setEditable(false);
        display.setComponentOrientation(ComponentOrientation.RIGHT_TO_LEFT);
        display.setPreferredSize(displayDimension);
        for(int i = 0; i < 14; i++)
            button[i].setPreferredSize(regularDimension);
        for(int i = 14; i < 18; i++)
            button[i].setPreferredSize(rColumnDimension);
        button[18].setPreferredSize(zeroButDimension);

        row[0].add(display);
        add(row[0]);

        for(int i = 0; i < 4; i++)
            row[1].add(button[i]);
        row[1].add(button[14]);
        add(row[1]);

        for(int i = 4; i < 8; i++)
            row[2].add(button[i]);
        row[2].add(button[15]);
        add(row[2]);

        for(int i = 8; i < 12; i++)
            row[3].add(button[i]);
        row[3].add(button[16]);
        add(row[3]);

        row[4].add(button[18]);
        for(int i = 12; i < 14; i++)
            row[4].add(button[i]);
        row[4].add(button[17]);
        add(row[4]);

        setVisible(true);
    }



//get the result
    public void getResult() {
        double result = 0;
        temp[1] = Double.parseDouble(display.getText());
        String temp0 = Double.toString(temp[0]);
        String temp1 = Double.toString(temp[1]);
        
        try {
            if(temp0.contains("-")) {
                String[] temp00 = temp0.split("-", 2);
                temp[0] = (Double.parseDouble(temp00[1]) * -1);
            }
            if(temp1.contains("-")) {
                String[] temp11 = temp1.split("-", 2);
                temp[1] = (Double.parseDouble(temp11[1]) * -1);
            }
        } catch(ArrayIndexOutOfBoundsException e) {
        }
        
        try {
            if(function[2] == true)
                result = temp[0] * temp[1];
            else if(function[3] == true)
                result = temp[0] / temp[1];
            else if(function[0] == true)
                result = temp[0] + temp[1];
            else if(function[1] == true)
                result = temp[0] - temp[1];

            display.setText(getJTextField1(Double.toString(result)));
            for(int i = 0; i < 4; i++)
                function[i] = false;
        } catch(NumberFormatException e) {
        }
    }

    
    //create a cool feel to the calculator. A theme!!!!
    public final void setDesign() {
        try {
            UIManager.setLookAndFeel(
                    "com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
        } catch(Exception e) {
        }
    }
    
    public void getPosNeg() {
      try {
          double value = Double.parseDouble(display.getText());
          if(value != 0) {
              value = value * (-1);
              display.setText(Double.toString(value));
          }
          else {
          }
      } catch(NumberFormatException e) {
      }
  }
  
    
    
    
//action!!!
    @Override
    public void actionPerformed(ActionEvent action_event) {;
        if(action_event.getSource() == button[0]){
            if(eval){
                display.setText("");
            }
            display.append("0");
        }

        if(action_event.getSource() == button[1]){
            if(eval){
                display.setText("");
            }
            display.append("1");
        }
        if(action_event.getSource() == button[2]){
            if(eval){
                display.setText("");
            }
            display.append("2");
        }
        if(action_event.getSource() == button[3]) {
            //add function[0]
            for (int i = 0; i < 4; i++){
                if(function[i] == true){
                    getResult();
                    eval = true;
                }
            }
            temp[0] = Double.parseDouble(display.getText());
            function[0] = true;
            if (!eval){
                display.setText("");
            }

        }
        if(action_event.getSource() == button[4]){
            if(eval){
                display.setText("");
            }
            display.append("3");
        }
        if(action_event.getSource() == button[5]){
            if(eval){
                display.setText("");
            }
            display.append("4");
        }
        if(action_event.getSource() == button[6]){
            if(eval){
                display.setText("");
            }
            display.append("5");
        }
        if(action_event.getSource() == button[7]) {
            //subtract function[1]
            for (int i = 0; i < 4; i++){
                if(function[i] == true){
                    getResult();
                    eval = true;
                }
            }
            temp[0] = Double.parseDouble(display.getText());
            function[1] = true;
            if (!eval){
                display.setText("");
            }
        }
        if(action_event.getSource() == button[8]){
            if(eval){
                display.setText("");
            }
            display.append("6");
        }
        if(action_event.getSource() == button[9]){
            if(eval){
                display.setText("");
            }
            display.append("7");
        }
        if(action_event.getSource() == button[10]){
            if(eval){
                display.setText("");
            }
            display.append("8");
        }
        if(action_event.getSource() == button[11]) {
            //multiply function[2]
            for (int i = 0; i < 4; i++){
                if(function[i] == true){
                    getResult();
                    eval = true;
                }
            }
            temp[0] = Double.parseDouble(display.getText());
            function[2] = true;
            if (!eval){
                display.setText("");
            }
        }
        if(action_event.getSource() == button[12])
            display.append(".");
        if(action_event.getSource() == button[13]) {
            //divide function[3]
            for (int i = 0; i < 4; i++){
                if(function[i] == true){
                    getResult();
                    eval = true;
                }
            }
            temp[0] = Double.parseDouble(display.getText());
            function[3] = true;
            if (!eval){
                display.setText("");
            }
        }
        
        if(action_event.getSource() == button[14]){
            clear();
        }
        if(action_event.getSource() == button[15]){
            display.append(")");
        }
        if(action_event.getSource() == button[16]){
            display.append("(");
        }
        if(action_event.getSource() == button[17]){
        
        
            getResult();
        }
        if(action_event.getSource() == button[18]){
            display.append("9");
        }
    }
    public void clear() {
      try {
          display.setText("");
          for(int i = 0; i < 4; i++)
              function[i] = false;
          for(int i = 0; i < 2; i++)
              temp[i] = 0;
      } catch(NullPointerException e) {
      }
  }

    //get the button label
    public JButton getButton(String label){
        for (int i = 0; i < 18; i ++) {
            if (label.equals(buttonString[i])) {
                return button[i];
            }
        }
        return null;
    }
    //return text field
    public JTextField getJTextField(){
      JTextField jtf1 = new JTextField(display.getText());
        return jtf1;
    }

    public String getJTextField1(String result){
      return result;
    }
    public static void main(String[] arguments) {
        Calculator c = new Calculator();
    }
}
