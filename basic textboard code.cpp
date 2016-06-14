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

        private void 大ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            current_font_size = 25;
            richTextBox1.Font = new Font("宋体", current_font_size);
        }

        private void 中ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            current_font_size = 18;
            richTextBox1.Font = new Font("宋体", current_font_size);
        }

        private void 小ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            current_font_size = 10;
            richTextBox1.Font = new Font("宋体", current_font_size);
        }

        private void 宋体ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Font = new Font("宋体", current_font_size);
        }

        private void 楷体ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Font = new Font("楷体", current_font_size);
        }

        private void 微软雅黑ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Font = new Font("微软雅黑", current_font_size);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = DateTime.Now.ToLongTimeString();
        }

        private void form1_MouseMove(object sender, MouseEventArgs e)
        {
            toolStripStatusLabel2.Text = "鼠标位置（X: " + e.X + "Y: " + e.Y + ")";
        }

        private void 新建ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //定义路径变量
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
                        MessageBox.Show("请输入完毕后再进行保存");
                    }
                    else
                    {

                        richTextBox1.Clear();
                        richTextBox1.Focus();
                    }
                }
                else
                {
                    MessageBox.Show("数据文件未打开");
                }
                sw.Close();
            }

           
                
          
        }

        private void 打开ToolStripMenuItem_Click(object sender, EventArgs e)
        {
           //定义路径变量
            string path;
            OpenFileDialog openfile = new OpenFileDialog();
            if (openfile.ShowDialog() == DialogResult.OK)
            {
                //获取路径变量的值
                path = openfile.FileName;
                StreamReader reader = File.OpenText(path);
                //读取目标文件的值
                richTextBox1.Text = richTextBox1.Text + reader.ReadLine();
                reader.Close();
            }
        }

        private void 保存ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FileStream fs = File.Create("test.txt");
            //初始化了一个SteamWrite对象
            StreamWriter sw = new StreamWriter((System.IO.Stream)fs);
            sw.WriteLine(richTextBox1.Text);


            if (sw != null)
            {
                if (richTextBox1.Text == "")
                {
                    MessageBox.Show("请输入完毕后再进行保存");
                }
                else
                {

                    richTextBox1.Clear();
                    richTextBox1.Focus();
                }
            }
            else
            {
                MessageBox.Show("数据文件未打开");
            }
            sw.Close();
        }

       

        private void button1_Click_1(object sender, EventArgs e)
        {
            //判断内容是否合法
            if (richTextBox1.Text == "")
            {
                MessageBox.Show("查找内容不能为空");
            }
            if (textBox3.Text == "")
            {
                MessageBox.Show("请输入您要查找的内容再进行查找");
            }
            string search_text =textBox3.Text;
            string root_text = richTextBox1.Text;


           
            int size = search_text.Length;
            //使用indexOf方法进行字符串匹配
            int index = root_text.IndexOf(search_text,size);
            richTextBox1.Select(index,size);
            //将查找到的对象进行颜色变换
            richTextBox1.SelectionColor = Color.Red;
            
          
            


        }

        private void button2_Click(object sender, EventArgs e)
        {
            //判断内容是否合法
            if (richTextBox1.Text == "")
            {
                MessageBox.Show("替换内容不能为空");
            }
            if (replace1.Text == "")
            {
                MessageBox.Show("请将您的要替换的内容输入完毕");
            }
            if (replace2.Text == "")
            {
                MessageBox.Show("请将您的要替换的内容输入完毕");
            }
            //定义替换前的字符串
            string replace_root = replace1.Text;
           //定义替换后的字符串
            string replace_text = replace2.Text;
            //调用replace方法进行替换
           richTextBox1.Text = richTextBox1.Text.Replace(replace_root,replace_text);
        }

      

      
    }
}
