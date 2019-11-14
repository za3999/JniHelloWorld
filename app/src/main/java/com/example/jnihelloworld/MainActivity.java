package com.example.jnihelloworld;

import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.example.jnihelloworld.bean.User;
import com.example.jnihelloworld.jni.Jni;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void test1(View view) {
        User user = new User("郑小才", "10010");
        Jni jni = new Jni();
        Toast.makeText(this, jni.getInt() + "|" + jni.add(4, 5) + "|" + jni.getUserName(user), Toast.LENGTH_LONG).show();
    }
}
