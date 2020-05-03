using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    // Start is called before the first frame update
    public Rigidbody rb;
    
    public float sidewaysForce = 500f;
    public float jumpForce = 50f;

    bool moveRight = false;
    bool moveLeft = false;
    bool jump = false;

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.RightArrow))
        {
            moveRight = true;   
        }

        if (Input.GetKey(KeyCode.LeftArrow))
        {
            moveLeft = true;
        }

        if (Input.GetKey(KeyCode.Space))
        {
            jump = true;
            
        }

        if (rb.position.y < -1)
        {
            FindObjectOfType<GameManager>().EndGame(); // don't use if you have multiple game managers and
        }
    }

    // Use FixedUpdate for physics related updates
    void FixedUpdate()
    {
        // Multiply by Time.deltaTime because of different computer settings and frame rates

        if (jump)
        {
            rb.AddForce(0, jumpForce, 0);
            jump = false;
        }
        if (moveLeft)
        {
            rb.AddForce(-sidewaysForce * Time.deltaTime, 0, 0, ForceMode.VelocityChange);
            moveLeft = false;
        }

        if (moveRight)
        {
            rb.AddForce(sidewaysForce * Time.deltaTime, 0, 0, ForceMode.VelocityChange);
            moveRight = false;
        }    
    }

    // will be called if there is a box collider and rigid body
    void OnCollisionEnter(Collision collisionInfo)
    {
        if(collisionInfo.collider.tag == "Obstacle")
        {
            enabled = false; // refers to player's movement, when hitting an obstacle the object only has inertia 
            GameManager.Instance.EndGame();
        }
    }
}
