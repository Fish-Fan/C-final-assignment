using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }
        ValidateCode vc = new ValidateCode();
        private string val = string.Empty;
        private void btn_creat_Click(object sender, EventArgs e)
        {
            int index;
            int index_line_color;
            this.txt_val.Text = "";
            if (letter.Checked)
            {
                this.val = vc.CreateValidateCode(Convert.ToInt32(num_length.Value),1);
            }
            else if (num.Checked)
            {
                this.val = vc.CreateValidateCode(Convert.ToInt32(num_length.Value),2);
            }
            else
            {
                 this.val = vc.CreateValidateCode(Convert.ToInt32(num_length.Value),3);
            }
            index = font_color.SelectedIndex;
            index_line_color = line_color.SelectedIndex;
            picBox.Image = new Bitmap(new MemoryStream(vc.CreateValidateGraphic(this.val, Convert.ToInt32(line.Value),
              Convert.ToInt32(font_size.Value), index,index_line_color)));
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            btn_creat_Click(null, null);
        }

        private void btn_val_Click(object sender, EventArgs e)
        {
            if (this.txt_val.Text == val)
            {
                MessageBox.Show("ÕýÈ·£¡");
            }
            else
            {
                MessageBox.Show("´íÎó£¡");
            }
        }
    }
}
