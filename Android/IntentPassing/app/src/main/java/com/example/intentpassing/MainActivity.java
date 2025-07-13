package com.example.intentpassing;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button btnPI = findViewById(R.id.btnPassInt);
        Intent iMainToSide = new Intent(MainActivity.this, SideActivity.class);

        iMainToSide.putExtra("key1","value1 passed via bundle passing"); //Bundle passing
        iMainToSide.putExtra("key2", 1);

        btnPI.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(iMainToSide);
            }
        });
    }
}