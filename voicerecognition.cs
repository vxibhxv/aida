using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Speech.Synthesis;
using System.Speech.Recognition;
using System.IO.Ports;
using System.Diagnostics;

namespace VoiceRecognition
{
    public partial class UserControl1: UserControl
    {
        SpeechSynthesizer s = new SpeechSynthesizer();
        Choices list = new Choices();
        SerialPort myport = new SerialPort("COM15");


        public UserControl1()
        {
            SpeechRecognitionEngine rec = new SpeechRecognitionEngine();

            list.Add(new String[] { "blade", "needle","drill","hammer" });

            Grammar gr = new Grammar(new GrammarBuilder(list));

            try
            {
                rec.RequestRecognizerUpdate();
                rec.LoadGrammar(gr);
                rec.SpeechRecognized += rec_SpeachRecognized;
                rec.SetInputToDefaultAudioDevice();
                rec.RecognizeAsync(RecognizeMode.Multiple);


            }
            catch { return; }

            s.SelectVoiceByHints(VoiceGender.Female);

            s.Speak("Hello!,My name is aida");

            InitializeComponent();

          init();
        }

       private void init()
        {
            myport.BaudRate = 9600;
            if(!myport.IsOpen)
            {
                myport.Open();
            }
        }

        public void say(String h)
        {
            s.Speak(h);
        }
        private void rec_SpeachRecognized(object sender, SpeechRecognizedEventArgs e)
        {
            String r = e.Result.Text;
            Debug.WriteLine(r);

            if (r == "needle")
            {
                
                myport.WriteLine("a");
                say("one");
            }

            else if(r=="blade")
            {


                myport.WriteLine("b");
                say("two");
            }
            else if (r == "drill")
            {

                
                myport.WriteLine("c");
                say("three");
            }
            else if (r == "hammer")
            {

                myport.WriteLine("d");
                say("four");
                
            }

        }

        private void UserControl1_Load(object sender, EventArgs e)
        {

        }

        
    }
}
