# 7-Segment Display with AVR Microcontrollers

A 7-segment display is an electronic display device used to represent numbers, letters, and sometimes other characters. It consists of seven LEDs arranged in a specific way that can be turned on or off to form different digits or characters. The display has 7 segments (labeled A to G) and an optional decimal point (DP). By turning different combinations of these segments on or off, it is possible to represent all the digits from 0 to 9, and in some cases, letters like A, b, C, etc.

<table>
  <tr>
  <td valign="top">
  
  > [!TIP]  
  > If you're looking to better understand how to navigate and use my GitHub repositories — including exploring their structure, downloading or cloning projects, submitting issues, and asking questions,  
  > everything you need is clearly explained in this video:  
  > [aKaReZa 95 - Programming, Git - PART B](https://youtu.be/zYiUItVFRqQ)  
  > Make sure to check it out!
  
  </td>
    <td width="360" valign="middle" style="padding: 0;">
      <a href="https://youtu.be/zYiUItVFRqQ">
       <img src="https://img.youtube.com/vi/zYiUItVFRqQ/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 95 - Programming, Git - PART B Thumbnail"/>
      </a>
    </td>

  </td>
  </tr>
  <tr>
  <td colspan="2">

  > [!CAUTION]
  > It is absolutely critical that you carefully read every single word of this document, line by line, to ensure you don't miss any details. Nothing can be overlooked.
      
  </td>
  </tr>  
</table>

# 🔗 Resources
  Here you'll find a collection of useful links and videos related to the topic of AVR microcontrollers.  


```
7-Segment Display Overview
├── Basics
│   ├─ Segment arrangement (A–G)
│   ├─ Digit/letter segment combinations
│   ├─ Common Cathode — wiring & logic
│   ├─ Common Anode — wiring & logic
│   └─ Hex code tables (0–F) + examples
│
├── Multiplexing
│   ├─ Multiplexing concept
│   ├─ Wiring for digit commons
│   ├─ Refresh rate requirements
│   ├─ Timing calculations
│   └─ Example — 4-digit switching sequence
│
└── API Reference
    ├─ CC_Hex_Array — 0–F hex values
    ├─ CA_Hex_Array — 0–F hex values
    └─ Multiplex_Example — sample C code
```

- [Basics](./Basics.md)
  ---
  Covers segment arrangement (A–G), digit/letter combinations, common cathode vs. common anode wiring and logic, and hexadecimal segment code tables for digits 0–F.

- [Multiplexing](./Multiplexing4Digit.md)
  ---
  Explains multiplexing operation for 4-digit displays, wiring of digit commons, refresh rate requirements, timing calculations, and example digit-switching sequence.

- [API Reference](./API_Reference.md)
  ---
  Provides C arrays for common cathode and common anode hexadecimal values (0–F) and a sample C implementation for multiplexed 7-segment display control.

```plaintext
 AVR, 7Segment
   ├── [aKaReZa 44 - AVR, 7Segment - Part A]
   │   ├─ Display Setup — Driving common anode + 4-digit multiplexing.
   │   └─ Code Quality — Readability and structure tips.
   │
   ├── [aKaReZa 47 - AVR, 7Segment - Part B]
   │   ├─ Buttons — Counter increment and input handling.
   │   ├─ Digit Split — Displaying digits individually.
   │   └─ Optimization — New macros for cleaner code.
   │
   └── [aKaReZa 53 - AVR, 7Segment - Part C]
       ├─ Modularization — Functions and headers.
       ├─ Refresh Issue — Software-based fix.
       └─ Timer — Implementing 1-second Timer.
```

<table style="border-collapse: collapse;">
  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/HGlJtcpjZ-E">aKaReZa 44 – AVR, 7Segment - Part A</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Learn how to set up a common anode 7-segment display with an AVR microcontroller on a breadboard, and then multiplex a four-digit 7-segment display using a custom shield to improve code readability.
      </p>
    </td>
    <td width="360" valign="top" style="padding: 0;">
      <a href="https://youtu.be/HGlJtcpjZ-E">
        <img src="https://img.youtube.com/vi/HGlJtcpjZ-E/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 44 – AVR, 7Segment - Part A Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/_pwxBJ06aMk">aKaReZa 47 – AVR, 7Segment - Part B</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Continuation of setting up 7-segment displays, building a counter, adding button functionality, displaying digits, optimizing code, and adding macros.
      </p>
    </td>
    <td width="360" valign="top" style="padding: 0;">
      <a href="https://youtu.be/_pwxBJ06aMk">
        <img src="https://img.youtube.com/vi/_pwxBJ06aMk/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 47 – AVR, 7Segment - Part B Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/5OG6KQWCLCA">aKaReZa 53 – AVR, 7Segment - Part C</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Continuation of setting up 7-segment displays, addressing three software issues: modular code writing, display refresh during button press, and one-second counting.
      </p>
    </td>
    <td width="360" valign="top" style="padding: 0;">
      <a href="https://youtu.be/5OG6KQWCLCA">
        <img src="https://img.youtube.com/vi/5OG6KQWCLCA/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 53 – AVR, 7Segment - Part C Thumbnail"/>
      </a>
    </td>
  </tr>
</table>

  
> [!TIP]
> The resources are detailed in the sections below.  
> To access any of them, simply click on the corresponding blue link.

- [AVR Microntroller](https://github.com/aKaReZa75/AVR)
  ---  
    This repository contains comprehensive resources for AVR microcontrollers, including hardware schematics, software libraries, and educational projects.

# 💻 How to Use Git and GitHub
To access the repository files and save them on your computer, there are two methods available:
1. **Using Git Bash and Cloning the Repository**
   - This method is more suitable for advanced users and those familiar with command-line tools.
   - By using this method, you can easily receive updates for the repository.

2. **Downloading the Repository as a ZIP file**
   - This method is simpler and suitable for users who are not comfortable with command-line tools.
   - Note that with this method, you will not automatically receive updates for the repository and will need to manually download any new updates.

## Clone using the URL.
First, open **Git Bash** :
-  Open the folder in **File Explorer** where you want the library to be stored.
-  **Right-click** inside the folder and select the option **"Open Git Bash here"** to open **Git Bash** in that directory.

![open Git Bash](Images/Step0.png)

> [!NOTE] 
> If you do not see the "Open Git Bash here" option, it means that Git is not installed on your system.  
> You can download and install Git from [this link](https://git-scm.com/downloads).  
> For a tutorial on how to install and use Git, check out [this video](https://youtu.be/BsykgHpmUt8).
  
-  Once **Git Bash** is open, run the following command to clone the repository:

 ```bash
git clone https://github.com/aKaReZa75/AVR_7Segments.git
```
- You can copy the above command by either:
- Clicking on the **Copy** button on the right of the command.
- Or select the command text manually and press **Ctrl + C** to copy.
- To paste the command into your **Git Bash** terminal, use **Shift + Insert**.

![Clone the Repository](Images/Step1.png)

- Then, press Enter to start the cloning operation and wait for the success message to appear.

![Open the Library File](Images/Step2.png)

> [!IMPORTANT]
> Please keep in mind that the numbers displayed in the image might vary when you perform the same actions.  
> This is because repositories are continuously being updated and expanded. Nevertheless, the overall process remains unchanged.

> [!NOTE]
> Advantage of Cloning the Repository:  
> - **Receiving Updates:** By cloning the repository, you can easily and automatically receive new updates.  
> - **Version Control:** Using Git allows you to track changes and revert to previous versions.  
> - **Team Collaboration:** If you are working on a project with a team, you can easily sync changes from team members and collaborate more efficiently.  

## Download Zip
If you prefer not to use Git Bash or the command line, you can download the repository directly from GitHub as a ZIP file.  
Follow these steps:  
1. Navigate to the GitHub repository page and Locate the Code button:
   - On the main page of the repository, you will see a green Code button near the top right corner.

2. Download the repository:
   - Click the Code button to open a dropdown menu.
   - Select Download ZIP from the menu.

  ![Download Zip](Images/Step7.png)  

3. Save the ZIP file:
   - Choose a location on your computer to save the ZIP file and click Save.

4. Extract the ZIP file:
   - Navigate to the folder where you saved the ZIP file.
   - Right-click on the ZIP file and select Extract All... (Windows) or use your preferred extraction tool.
   - Choose a destination folder and extract the contents.

5. Access the repository:
   - Once extracted, you can access the repository files in the destination folder.

> [!IMPORTANT]
> - No Updates: Keep in mind that downloading the repository as a ZIP file does not allow you to receive updates.    
>   If the repository is updated, you will need to download it again manually.  
> - Ease of Use: This method is simpler and suitable for users who are not comfortable with Git or command-line tools.

# 📝 How to Ask Questions
If you have any questions or issues, you can raise them through the **"Issues"** section of this repository. Here's how you can do it:  

1. Navigate to the **"Issues"** tab at the top of the repository page.  

  ![Issues](Images/Step3.png)

2. Click on the **"New Issue"** button.  
   
  ![New Issue](Images/Step4.png)

3. In the **Title** field, write a short summary of your issue or question.  

4. In the "Description" field, detail your question or issue as thoroughly as possible. You can use text formatting, attach files, and assign the issue to someone if needed. You can also use text formatting (like bullet points or code snippets) for better readability.  

5. Optionally, you can add **labels**, **type**, **projects**, or **milestones** to your issue for better categorization.  

6. Click on the **"Submit new issue"** button to post your question or issue.
   
  ![Submeet New Issue](Images/Step5.png)

I will review and respond to your issue as soon as possible. Your participation helps improve the repository for everyone!  

> [!TIP]
> - Before creating a new issue, please check the **"Closed"** section to see if your question has already been answered.  
>   ![Closed section](Images/Step6.png)  
> - Write your question clearly and respectfully to ensure a faster and better response.  
> - While the examples provided above are in English, feel free to ask your questions in **Persian (فارسی)** as well.  
> - There is no difference in how they will be handled!  

> [!NOTE]
> Pages and interfaces may change over time, but the steps to create an issue generally remain the same.

# 🤝 Contributing to the Repository
To contribute to this repository, please follow these steps:
1. **Fork the Repository**  
2. **Clone the Forked Repository**  
3. **Create a New Branch**  
4. **Make Your Changes**  
5. **Commit Your Changes**  
6. **Push Your Changes to Your Forked Repository**  
7. **Submit a Pull Request (PR)**  

> [!NOTE]
> Please ensure your pull request includes a clear description of the changes you’ve made.
> Once submitted, I will review your contribution and provide feedback if necessary.

# 🌟 Support Me
If you found this repository useful:
- Subscribe to my [YouTube Channel](https://www.youtube.com/@aKaReZa75).
- Share this repository with others.
- Give this repository and my other repositories a star.
- Follow my [GitHub account](https://github.com/aKaReZa75).

# 📜 License
This project is licensed under the GPL-3.0 License. This license grants you the freedom to use, modify, and distribute the project as long as you:
- Credit the original authors: Give proper attribution to the original creators.
- Disclose source code: If you distribute a modified version, you must make the source code available under the same GPL license.
- Maintain the same license: When you distribute derivative works, they must be licensed under the GPL-3.0 too.
- Feel free to use it in your projects, but make sure to comply with the terms of this license.
  
# ✉️ Contact Me
Feel free to reach out to me through any of the following platforms:
- 📧 [Email: aKaReZa75@gmail.com](mailto:aKaReZa75@gmail.com)
- 🎥 [YouTube: @aKaReZa75](https://www.youtube.com/@aKaReZa75)
- 💼 [LinkedIn: @akareza75](https://www.linkedin.com/in/akareza75)
