package com.example.roomlibraryexample;


import androidx.room.ColumnInfo;
import androidx.room.Entity;
import androidx.room.Ignore;
import androidx.room.PrimaryKey;

//Entity class , corresponds to table
@Entity (tableName = "Expense_Table")
public class Expense {
    //fields correspond to table columns
    @PrimaryKey(autoGenerate = true)
    private int id;

    @ColumnInfo(name = "Title")
    private String title;

    @ColumnInfo(name = "Amount")
    private String amount;


    Expense(int id, String title, String amount){
        this.id = id;
        this.title = title;
        this.amount = amount;

    }

    @Ignore
    Expense(String title, String amount){
        this.title = title;
        this.amount = amount;

    }

    public int getId() {
        return id;
    }

    /*public void setId(int id) { //isn't needed as id is set to auto increment
        this.id = id;
    } */

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getAmount() {
        return amount;
    }

    public void setAmount(String amount) {
        this.amount = amount;
    }
}
