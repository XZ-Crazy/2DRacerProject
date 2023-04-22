using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
using System;
using UnityEngine.SceneManagement;

public class Timer : MonoBehaviour
{
    public bool timerActive = false;
    public float currentTime;
    public TextMeshProUGUI currentTimeText;
    private float savedTime;
    public float silverLimit;//limit in seconds
    public float goldLimit; //limit in seconds
    
    void Start()
    {
        currentTime = 0; //makes the initial time 0
        StartTime();
    }

    // Update is called once per frame
    void Update()
    { 
    
        if (timerActive == true) //checks if timer is active
        {
            currentTime += Time.deltaTime; //if timer is active increment time by Time.deltaTime
        }
        
        TimeSpan time = TimeSpan.FromSeconds(currentTime); //I don't really know what this does but it helps display the time
        currentTimeText.text = time.ToString(@"mm\:ss\:ff"); //display the time in proper format mm\:ss\:ff
    }


    public void StartTime() //starts stopwatch
    {
        medalText.text = ""; //sets medal text to nothing
        timerActive = true; //activates stopwatch
    }

    public void StopTime() //stops stopwatch
    {
        timerActive = false; //deactivates the stopwatch
    }

    public void ClearTime() //clears the time
    {
        currentTime = 0; //sets current and saved time to 0
        savedTime = 0;
        popup.medalText.text = ""; //sets the medalText to nothing
        TimeSpan time = TimeSpan.FromSeconds(currentTime); //displays the time as 0 on screen
        currentTimeText.text = time.ToString(@"mm\:ss\:ff");
    }

    public void SaveTime() //saves time
    {
        savedTime = currentTime; //saves the time when method is activated
    }

    public void LoadTime() //loads time
    {
        currentTime = savedTime; //sets current time to whatever was activated
        TimeSpan time = TimeSpan.FromSeconds(currentTime); //displays the saved time
        currentTimeText.text = time.ToString(@"mm\:ss\:ff");
    }

}