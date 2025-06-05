using System.IO.Ports;
using System.Security.Cryptography;

namespace SerialController;

class Program
{
    static SerialPort serial;

    static void Main()
    {
        string portName = "/dev/ttyUSB0"; // Change this to match your ESP32's port
        int baudRate = 115200;

        serial = new SerialPort(portName, baudRate)
        {
            NewLine = "\n",
            ReadTimeout = 2000,
            WriteTimeout = 2000
        };

        try
        {
            serial.Open();
            Console.WriteLine($"Opened port {portName}.");

            // Optional delay if ESP32 auto-resets on serial open
            Thread.Sleep(1500);
            
            ReadResponse();

            while (true)
            {
                var key = Console.ReadKey();

                if (key.Key == ConsoleKey.Q)
                {
                    break;
                }
                
                SendCommand(key.KeyChar.ToString());

                if (serial.BytesToRead > 0)
                {
                    ReadResponse();
                }
            }

            serial.Close();
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Serial error: {ex.Message}");
        }
    }

    static void SendCommand(string command)
    {
        Console.WriteLine($">> {command}");
        
        serial.WriteLine(command);
    }

    static void ReadResponse()
    {
        var response = serial.ReadExisting();
        
        Console.WriteLine($"<< {response}");
    }
}