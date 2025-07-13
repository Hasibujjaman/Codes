//Splash Screen Activity
package com.example.sharedpreferenceexample1;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Handler;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {

                SharedPreferences pref = getSharedPreferences("login", MODE_PRIVATE);
                boolean is_loggedIn = pref.getBoolean("key",false);

                Intent intent;
                if(is_loggedIn)
                    intent = new Intent(MainActivity.this, HomeActivity.class);
                else
                    intent = new Intent(MainActivity.this, LoginActivity.class);

                startActivity(intent);



            }
        },3000);




    }
}