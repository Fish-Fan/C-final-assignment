using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApplication1
{
    public partial class form1 : Form
    {
       
       
        public form1()
        {
            
            InitializeComponent();
           
        }
        string root1;
        int current_font_size;
        private void copy_button_Click(object sender, EventArgs e)
        {

            root1 = richTextBox1.Text;
           
            
            
            
        }
        
        private void cut_button_Click(object sender, EventArgs e)
        {

            root1 = richTextBox1.Text;
            richTextBox1.Text = "";
            

        }

        private void stick_button_Click(object sender, EventArgs e)
        {
            textBox2.Text += root1;
        }

        private void ��ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            current_font_size = 25;
            richTextBox1.Font = new Font("����", current_font_size);
        }

        private void ��ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            current_font_size = 18;
            richTextBox1.Font = new Font("����", current_font_size);
        }

        private void СToolStripMenuItem_Click(object sender, EventArgs e)
        {
            current_font_size = 10;
            richTextBox1.Font = new Font("����", current_font_size);
        }

        private void ����ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Font = new Font("����", current_font_size);
        }

        private void ����ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Font = new Font("����", current_font_size);
        }

        private void ΢���ź�ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Font = new Font("΢���ź�", current_font_size);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = DateTime.Now.ToLongTimeString();
        }

        private void form1_MouseMove(object sender, MouseEventArgs e)
        {
            toolStripStatusLabel2.Text = "���λ�ã�X: " + e.X + "Y: " + e.Y + ")";
        }

        private void �½�ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //����·������
            string path;
            
            OpenFileDialog openfile = new OpenFileDialog();
            if (openfile.ShowDialog() == DialogResult.OK)
            {
                path = openfile.FileName;
                FileStream fs = File.Create(path);
                StreamWriter sw = new StreamWriter((System.IO.Stream)fs);
                sw.WriteLine(richTextBox1.Text);


                if (sw != null)
                {
                    if (richTextBox1.Text == "")
                    {
                        MessageBox.Show("��������Ϻ��ٽ��б���");
                    }
                    else
                    {

                        richTextBox1.Clear();
                        richTextBox1.Focus();
                    }
                }
                else
                {
                    MessageBox.Show("�����ļ�δ��");
                }
                sw.Close();
            }

           
                
          
        }

        private void ��ToolStripMenuItem_Click(object sender, EventArgs e)
        {
           //����·������
            string path;
            OpenFileDialog openfile = new OpenFileDialog();
            if (openfile.ShowDialog() == DialogResult.OK)
            {
                //��ȡ·��������ֵ
                path = openfile.FileName;
                StreamReader reader = File.OpenText(path);
                //��ȡĿ���ļ���ֵ
                richTextBox1.Text = richTextBox1.Text + reader.ReadLine();
                reader.Close();
            }
        }

        private void ����ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FileStream fs = File.Create("test.txt");
            //��ʼ����һ��SteamWrite����
            StreamWriter sw = new StreamWriter((System.IO.Stream)fs);
            sw.WriteLine(richTextBox1.Text);


            if (sw != null)
            {
                if (richTextBox1.Text == "")
                {
                    MessageBox.Show("��������Ϻ��ٽ��б���");
                }
                else
                {

                    richTextBox1.Clear();
                    richTextBox1.Focus();
                }
            }
            else
            {
                MessageBox.Show("�����ļ�δ��");
            }
            sw.Close();
        }

       

        private void button1_Click_1(object sender, EventArgs e)
        {
            //�ж������Ƿ�Ϸ�
            if (richTextBox1.Text == "")
            {
                MessageBox.Show("�������ݲ���Ϊ��");
            }
            if (textBox3.Text == "")
            {
                MessageBox.Show("��������Ҫ���ҵ������ٽ��в���");
            }
            string search_text =textBox3.Text;
            string root_text = richTextBox1.Text;


           
            int size = search_text.Length;
            //ʹ��indexOf���������ַ���ƥ��
            int index = root_text.IndexOf(search_text,size);
            richTextBox1.Select(index,size);
            //�����ҵ��Ķ��������ɫ�任
            richTextBox1.SelectionColor = Color.Red;
            
          
            


        }

        private void button2_Click(object sender, EventArgs e)
        {
            //�ж������Ƿ�Ϸ�
            if (richTextBox1.Text == "")
            {
                MessageBox.Show("�滻���ݲ���Ϊ��");
            }
            if (replace1.Text == "")
            {
                MessageBox.Show("�뽫����Ҫ�滻�������������");
            }
            if (replace2.Text == "")
            {
                MessageBox.Show("�뽫����Ҫ�滻�������������");
            }
            //�����滻ǰ���ַ���
            string replace_root = replace1.Text;
           //�����滻����ַ���
            string replace_text = replace2.Text;
            //����replace���������滻
           richTextBox1.Text = richTextBox1.Text.Replace(replace_root,replace_text);
        }

      

      
    }
}
