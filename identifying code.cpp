using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApplication1
{
    /// <summary>
    /// 生成验证码的类
    /// </summary>
    public class ValidateCode
    {
        public ValidateCode()
        {
        }
        /// <summary>
        /// 验证码的最大长度
        /// </summary>
        public int MaxLength
        {
            get { return 10; }
        }
        /// <summary>
        /// 验证码的最小长度
        /// </summary>
        public int MinLength
        {
            get { return 1; }
        }
        Random rd = new Random();
        /// <summary>
        /// 生成验证码
        /// </summary>
        /// <param name="length">指定验证码的长度</param>
        /// <returns></returns>
        public string CreateValidateCode(int length,int switch_num)
        {
            string[] validateStrs_letter = new string[] { 
                "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
                "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

            string[] validateStrs_num = new string[] { "0" ,"1","2", "3", "4", "5", "6", "7", "8", "9"
                 };

            string[] validateStrs = new string[] { "0" ,"1","2", "3", "4", "5", "6", "7", "8", "9",
                "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
                "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
           
            StringBuilder validateSB = new StringBuilder();
            //选择验证码类型
            switch (switch_num)
            {
                case 1:
                    for (int i = 0; i < length; i++)
                    {
                        int num = rd.Next(0, validateStrs_letter.Length - 1);
                        validateSB.Append(validateStrs_letter[num]);
                    }
                    break;
                case 2:
                    for (int i = 0; i < length; i++)
                    {
                        int num = rd.Next(0, validateStrs_num.Length - 1);
                        validateSB.Append(validateStrs_num[num]);
                    }
                    break;
                case 3:
                    for (int i = 0; i < length; i++)
                    {
                        int num = rd.Next(0, validateStrs.Length - 1);
                        validateSB.Append(validateStrs[num]);
                    }
                    break;


            }




            return validateSB.ToString();
        }

        /// <summary>
        /// 创建验证码的图片
        /// </summary>
        /// <param name="containsPage">要输出到的page对象</param>
        /// <param name="validateNum">验证码</param>
        public byte[] CreateValidateGraphic(string validateCode,int num_line,int font_size,int font_color,int line_color)
        {
            Bitmap image = new Bitmap((int)Math.Ceiling(Convert.ToDecimal(GetImageWidth(validateCode.Length))), 48);
            Graphics g = Graphics.FromImage(image);
            //RectangleF rectangle = new RectangleF(0, 0, 36, 16);
            
            try
            {
                //生成随机生成器
                Random random = new Random();
                //清空图片背景色
                g.Clear(Color.White);
                //画图片的干扰线
                for (int i = 0; i < num_line; i++)
                {
                    int x1 = random.Next(image.Width);
                    int x2 = random.Next(image.Width);
                    int y1 = random.Next(image.Height);
                    int y2 = random.Next(image.Height);
                    //选择干扰线的颜色
                    if(line_color == 0)
                    {
                         g.DrawLine(new Pen(Color.Black), x1, y1, x2, y2);
                    }
                    else if (line_color == 1)
                    {
                        g.DrawLine(new Pen(Color.Brown), x1, y1, x2, y2);
                    }
                    else if (line_color == 2)
                    {
                        g.DrawLine(new Pen(Color.DarkGreen), x1, y1, x2, y2);
                    }
                    else
                    {
                        g.DrawLine(new Pen(Color.Silver), x1, y1, x2, y2);
                    }
                }
                Font font = new Font("Arial", font_size, (FontStyle.Bold | FontStyle.Italic));
                int j;
                for (j = 0; j < validateCode.Length;j++)
                {
                    StringFormat srFormat = new StringFormat(StringFormatFlags.NoClip);
                    srFormat.Alignment = StringAlignment.Center;
                    srFormat.LineAlignment = StringAlignment.Center;
                    float srangle = random.Next(-30, 30);
                    Point point = new Point(16,16);
                    g.TranslateTransform(point.X, point.Y);
                    g.RotateTransform(srangle);

                    //选择字体的颜色
                    if (font_color == 0)
                    {
                        LinearGradientBrush brush = new LinearGradientBrush(new Rectangle(0, 0, image.Width, image.Height),
                    Color.Red, Color.DarkRed, 1.2f, true);
                        g.DrawString(validateCode[j].ToString(), font, brush, 3, 2,srFormat);

                    }
                    else if (font_color == 1)
                    {
                        LinearGradientBrush brush = new LinearGradientBrush(new Rectangle(0, 0, image.Width, image.Height),
                   Color.Blue, Color.DarkRed, 1.2f, true);
                        g.DrawString(validateCode[j].ToString(), font, brush, 3, 2,srFormat);
                    }
                    else if (font_color == 2)
                    {
                        LinearGradientBrush brush = new LinearGradientBrush(new Rectangle(0, 0, image.Width, image.Height),
                   Color.LightGreen, Color.DarkRed, 1.2f, true);
                        g.DrawString(validateCode[j].ToString(), font, brush, 3, 2,srFormat);
                    }
                    else
                    {
                        LinearGradientBrush brush = new LinearGradientBrush(new Rectangle(0, 0, image.Width, image.Height),
                   Color.Black, Color.DarkRed, 1.2f, true);
                        g.DrawString(validateCode[j].ToString(), font, brush, 3, 2,srFormat);
                    }
                    g.RotateTransform(-srangle);
                    g.TranslateTransform(2, -point.Y);
                }
               
               
                //画图片的前景干扰点
                for (int i = 0; i < 200; i++)
                {
                    int x = random.Next(image.Width);
                    int y = random.Next(image.Height);
                    image.SetPixel(x, y, Color.FromArgb(random.Next()));
                }
                //画图片的边框线
                g.DrawRectangle(new Pen(Color.Silver), -531, 0, image.Width - 1, image.Height - 1);
                //保存图片数据
                MemoryStream stream = new MemoryStream();
                image.Save(stream, ImageFormat.Jpeg);
                //输出图片流
                return stream.ToArray();
            }
            finally
            {
                g.Dispose();
                image.Dispose();
            }
        }
        /// <summary>
        /// 得到验证码图片的长度
        /// </summary>
        /// <param name="validateNumLength">验证码的长度</param>
        /// <returns></returns>
        public static int GetImageWidth(int validateNumLength)
        {
            return (int)(validateNumLength * 80.0);
        }
        /// <summary>
        /// 得到验证码的高度
        /// </summary>
        /// <returns></returns>
        public static double GetImageHeight()
        {
            return 0;
        }
    }
}
