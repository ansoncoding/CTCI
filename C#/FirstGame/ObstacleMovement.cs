﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ObstacleMovement : MonoBehaviour
{
    public Rigidbody rb;
    public float forwardForce = 2000f;

    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody>();
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        rb.AddForce(0, 0, -forwardForce * Time.deltaTime);
    }

    void Update()
    {
        if (transform.position.z < -50f)
        {
            GameManager.Instance.incPoints();
            Destroy(gameObject);
        }
    }
}
