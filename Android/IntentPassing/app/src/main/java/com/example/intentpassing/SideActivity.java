package com.example.intentpassing;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;


public class SideActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_side);

        Intent inFromMain = getIntent();
        String val1 = inFromMain.getStringExtra("key1");
        int val2 = inFromMain.getIntExtra("key2", 0);

        TextView txtB = findViewById(R.id.txtBP);
        txtB.setText(val1);
        getSupportActionBar().setTitle(Integer.toString(val2));

    }
}