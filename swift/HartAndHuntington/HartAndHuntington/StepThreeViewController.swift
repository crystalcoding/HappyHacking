//
//  StepThreeViewController.swift
//  HartAndHuntington
//
//  Created by SecondForm.com on 10/26/14.
//  Copyright (c) 2014 HartAndHuntington. All rights reserved.
//

import UIKit

class StepThreeViewController: UIViewController {

    @IBAction func nextButton(sender: AnyObject) {
        let vc = StepFourViewController(nibName: "StepFourViewController", bundle: nil)
        navigationController?.pushViewController(vc, animated: true)
    }
    
    
    @IBAction func backButton(sender: AnyObject) {
        navigationController?.popViewControllerAnimated(true)
    }
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
