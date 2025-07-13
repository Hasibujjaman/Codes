package com.example.cardviewexample;

import androidx.appcompat.app.AppCompatActivity;
import androidx.cardview.widget.CardView;

import android.os.Bundle;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        CardView cardView = findViewById(R.id.cardView2);
        cardView.setRadius(5.0f);
        cardView.setElevation(11.0f);
        cardView.setUseCompatPadding(true);
        cardView.setBackgroundColor(getResources().getColor(R.color.myColor));
    }
}