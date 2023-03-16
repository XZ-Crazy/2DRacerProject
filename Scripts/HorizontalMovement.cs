using System.Collections;
using System.Collections.Generic;
using System.Threading;
using UnityEngine;

public class HorizontalMovement : MonoBehaviour
{
    public float Velocity = 20f;
    public int Gear = 2;
    public Rigidbody2D rb;

    void Start()
    {
        
    }

    void Update()
    {
        rb.AddForce(new Vector2(Velocity*Time.deltaTime, 0));
    }
}
