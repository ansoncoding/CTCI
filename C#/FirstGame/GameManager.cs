using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    int totalPoints = 0;
    float restartDelay = 1f;
    private int currentLevel = 1;
    Text levelText;

    private static GameManager instance;

    const int LEVEL1_COMPLETE = 100;
    const int LEVEL2_COMPLETE = 400;
    const int LEVEL3_COMPLETE = 800;

    public void incPoints()
    {
        totalPoints += currentLevel * 10;
        if ((currentLevel == 1 && totalPoints >= LEVEL1_COMPLETE) ||
            (currentLevel == 2 && totalPoints >= LEVEL2_COMPLETE))
        {
            currentLevel++;
        }
        else if (currentLevel == 3 && totalPoints >= LEVEL3_COMPLETE) {
            // You won
        }
    }
    public int getLevel()
    {
        return currentLevel;
    }

    public int getPoints()
    {
        return totalPoints;
    }

    

    public static GameManager Instance { get { return instance; } }


    private void Awake()
    {
        if (instance != null && instance != this)
        {
            Destroy(this.gameObject);
        }
        else
        {
            instance = this;
        }
    }

    public void EndGame()
    {
        Invoke("Restart", restartDelay);   
    }

    void Restart()
    {
        totalPoints = 0;
        currentLevel = 1;
        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex); // Reload the current level
        // You can also use SceneManager.LoadScene(SceneManager.GetActiveScene().name); 
    }
}
